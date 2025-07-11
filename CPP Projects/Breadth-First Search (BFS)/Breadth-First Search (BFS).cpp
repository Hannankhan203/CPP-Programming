#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
	int V;
	vector<vector<int>> adj;
	
	public:
		Graph(int V) : V(V), adj(V) {}
		
		void addEdge(int u, int v) {
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		void BFS(int start) {
			vector<bool> visited(V, false);
			queue<int> q;
			
			visited[start] = true;
			q.push(start);
			
			cout << "BFS Traversal: ";
			
			while(!q.empty()) {
				int node = q.front(); q.pop();
				cout << node << " ";
				
				for(int neighbor : adj[node]) {
					if(!visited[neighbor]) {
						visited[neighbor] = true;
						q.push(neighbor);
					}
				}
			}
			cout << endl;
		}
};

int main() {
	Graph g(6);
	g.addEdge(0, 1); g.addEdge(0, 2);
	g.addEdge(1, 3); g.addEdge(2, 4); g.addEdge(3, 5);
	
	g.BFS(0);
	
	return 0;
}