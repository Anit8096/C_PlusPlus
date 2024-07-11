#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int vertices; // Number of vertices in the graph
    vector<vector<int>> AdjMatrix; // Adjacency matrix to represent edges

public:
    // Constructor to initialize the graph with a given number of vertices
    Graph (int v) {
        this->vertices = v;
        // Resize the adjacency matrix to be v x v and initialize with 0
        AdjMatrix = vector<vector<int>> (vertices, vector<int> (vertices, 0));
    }

    // Method to add an edge between vertices u and v
    // If Directed is false, the edge is undirected
    void addEdge (int u, int v, bool Directed = false) {
        AdjMatrix[u][v] = 1; // Add edge from u to v
        if (!Directed) {
            AdjMatrix[v][u] = 1; // Add edge from v to u for undirected graph
        }
    }

    // Method to print the adjacency matrix of the graph
    void printGraph (void) {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << AdjMatrix[i][j] << " "; 
            }
            cout << endl; 
        }
    }
};

int main() {
    Graph g(5); // Create a graph with 5 vertices

    
    g.addEdge(0, 1);           // Add an undirected edge between 0 and 1
    g.addEdge(0, 2, true);     // Add a directed edge from 0 to 2
    g.addEdge(1, 2);           // Add an undirected edge between 1 and 2
    g.addEdge(1, 3);           // Add an undirected edge between 1 and 3
    g.addEdge(2, 3, true);     // Add a directed edge from 2 to 3
    g.addEdge(3, 4);           // Add an undirected edge between 3 and 4

    g.printGraph();

    return 0;
}
