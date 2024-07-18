#include <iostream>
#include <vector>
using namespace std;

vector <vector <int>> Creat_AdjList (vector <vector <int>>& Edges, int vertice, bool Directed = false) {
    // Initialize the adjacency list 
    vector <vector <int>> AdjList(vertice);
    // Fill the adjacency list based on the edges in the graph
    for (auto& Edge : Edges) {
        int u = Edge[0];
        int v = Edge[1];
        AdjList[u].push_back(v);
        if (!Directed)
            AdjList[v].push_back(u);
    }
    return AdjList;
}

int main() {
    // Undirected Graph of 4 nodes
    int numVertices = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}, {3, 1}};

    // Create the adjacency List
    vector<vector<int>> adjList = Creat_AdjList(edges, numVertices);

    // Print the adjacency List
    for (int i = 0; i < numVertices; ++i) {
        cout << i << " -> ";
        for (auto List : adjList[i]) {
            cout << List << " ";
        }
        cout << endl;
    }

    return 0;
}