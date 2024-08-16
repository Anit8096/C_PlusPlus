#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

const int INF = numeric_limits<int>:max();

vector <vector <int>> Create_AdjMatrix(vector <vector <int>>& Edges, int vertices, bool directed = false) {
    // initialise Adj matrix using INF instead of 0
    vector <vector <int>> AdjMatrix (vertices, vector <int>(vertices, INF));

    // Fill adj-matrix using the given edges and there weights
    for(const auto& Edge : Edges) {
        int u = Edge[0];
        int v = Edge[1];
        int weight = Edge[2];
        AdjMatrix[u][v] = weight;
        if (!directed) 
            AdjMatrix[v][u] = weight;
    }

    // Optional: Set diagonal to 0 (distance from a node to itself is zero)
    for (int i = 0; i < Vertice; ++i) {
        AdjMatrix[i][i] = 0;
    }

    return AdjMatrix;
} 

// Function to implement Dijkstra's Algorithm using an adjacency matrix
vector<int> dijkstra(int start, const vector<vector<int>>& adjMatrix) {
    int n = adjMatrix.size();
    vector<int> distances(n, INF);
    vector<bool> visited(n, false);
    distances[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [dist, current] = pq.top();
        pq.pop();

        if (visited[current]) continue;
        visited[current] = true;

        for (int i = 0; i < n; ++i) {
            if (adjMatrix[current][i] != INF) { // If there is an edge
                int newDist = distances[current] + adjMatrix[current][i];
                if (newDist < distances[i]) {
                    distances[i] = newDist;
                    pq.push({newDist, i});
                }
            }
        }
    }

    return distances;
}