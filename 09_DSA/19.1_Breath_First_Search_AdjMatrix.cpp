#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// Function to create adjacency matrix from edges
vector<vector<int>> Create_AdjMatrix(const vector<vector<int>>& Edges, int Vertice, bool Directed = false) {
    // Initialize the adjacency matrix with zeros
    vector<vector<int>> AdjMatrix(Vertice, vector<int>(Vertice, 0));
    
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

// Function to perform BFS on the adjacency matrix
void BFS(const vector<vector<int>>& adjMatrix, int startNode) {
    int numNodes = adjMatrix.size();
    vector<bool> visited(numNodes, false);
    queue<int> q;
    
    // Start from the given node
    visited[startNode] = true;
    q.push(startNode);
    
    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";
        
        // Visit all the neighbors of the current node
        for (int i = 0; i < numNodes; ++i) {
            if (adjMatrix[currentNode][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

// Function to print the adjacency matrix
void PrintMatrix(const vector<vector<int>>& AdjMatrix) {
    for (const auto& row : AdjMatrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Edges of the graph
    vector<vector<int>> Edges = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}
    };

    // Find the number of vertices
    int vertices = 0;
    for (const auto& edge : Edges) {
        vertices = max(vertices, max(edge[0], edge[1]) + 1);
    }

    vector<vector<int>> adjMatrix = Create_AdjMatrix(Edges, vertices);

    cout << "Adjacency Matrix:" << endl;
    PrintMatrix(adjMatrix);

    int startNode = 0; // Starting node for BFS
    cout << "BFS Traversal starting from node " << startNode << ": ";
    BFS(adjMatrix, startNode);

    return 0;
}
