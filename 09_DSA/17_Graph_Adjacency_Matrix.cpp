#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> AdjMatrix;
public:
    Graph (int v) {
        this->vertices = v;
        AdjMatrix = vector<vector<int>> (vertices, vector<int> (vertices, 0));
    }

    void addEdge (int u, int v, bool Directed = false) {
        AdjMatrix[u][v] = 1;
        if (!Directed) {
            AdjMatrix[v][u] = 1;
        }
    }

    void printGraph (void) {
        for (int i = 0; i < vertices: i++) {
            for (int j = 0; j< vertices; j++) {
                cout<<AdjMatrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}