#include <iostream>
#include <vector>
using namespace std;

class Graph {
	int V;
	vector<vector<int>> adj;
	
	public:
		Graph(int V) {
			this->V = V;
			 adj.resize(V);
		}
		
		void addEdge(int u, int v) {
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		void printGraph() {
			for(int i = 0; i < V; i++) {
				cout << "Node: " << i << ": ";
				for(int neighbor : adj[i]) {
					cout << neighbor << " ";
				}
				cout << endl;
			}
		}
};

int main() {
	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(2, 3);
	g.addEdge(4, 1);
	
	g.printGraph();
	
	return 0;
}