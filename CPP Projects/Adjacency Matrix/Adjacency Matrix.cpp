#include <iostream>
using namespace std;

class GraphMatrix {
	int V;
	int **matrix;
	
	public:
		GraphMatrix(int V) {
			this->V = V;
			matrix = new int *[V];
			for(int i = 0; i < V; ++i) {
				matrix[i] = new int[V]{0};
			}
		}
		
		void addEdge(int u, int v) {
			matrix[u][v] = 1;
			matrix[v][u] = 1;
		}
		
		void printMatrix() {
			cout << "Adjacency Matrix:\n";
			for(int i = 0; i < V; ++i) {
				for(int j = 0; j < V; ++j) {
					cout << matrix[i][j] << " ";
				}
				cout << endl;
			}
		}
		
		~GraphMatrix() {
			for(int i = 0; i < V; ++i) {
				delete[] matrix[i];
				delete[] matrix;
			}
		}
};

int main() {
	GraphMatrix g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	
	g.printMatrix();
	
	return 0;
}