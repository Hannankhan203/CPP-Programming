#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

void unionSet(int parent[], int x, int y) {
    parent[find(parent, x)] = find(parent, y);
}

void KruskalMST(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end(), compare);
    int parent[V];
    for (int i = 0; i < V; i++) parent[i] = i;

    vector<Edge> result;
    for (auto& edge : edges) {
        int x = find(parent, edge.src);
        int y = find(parent, edge.dest);

        if (x != y) {
            result.push_back(edge);
            unionSet(parent, x, y);
        }
    }

    cout << "Edges in MST:\n";
    for (auto& e : result)
        cout << e.src << " - " << e.dest << " : " << e.weight << endl;
}

int main() {
    int V = 4;
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4},
    };

    KruskalMST(edges, V);
}
