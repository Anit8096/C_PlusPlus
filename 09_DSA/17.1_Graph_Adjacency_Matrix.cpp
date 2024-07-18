#include <iostream>
#include <vector>
using namespace std;

vector <vector <int>> Create_AdjMatrix (vector <vector<int>>& Edges, int Vertice, bool Directed = false) {
    // Initialize the adjacency matrix with zeros
    vector <vector <int>> AdjMatrix (Vertice, vector <int> (Vertice, 0));
    // Fill the adjacency matrix based on the edges in the graph
    for (const auto& edge : Edges) {
        int u = edge[0];
        int v = edge[1];
        AdjMatrix[u][v] = 1;
        if (!Directed) {
            AdjMatrix[v][u] = 1;
        }
    }
    
    return AdjMatrix;
}

int main()
{
    // The indices represent the vertices, and the values
    // are lists of neighboring vertices
    vector<vector<int> > edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}, {3, 1}};

    int numVertices = edges.size();

    // Create the adjacency matrix
    vector<vector<int> > adjMatrix = Create_AdjMatrix(edges, numVertices);

    // Print the adjacency matrix
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}