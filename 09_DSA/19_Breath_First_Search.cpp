#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to create adjacency list from edges
vector <vector <int>> Create_AdjList (vector <vector <int>>& Edges, int vertice, bool Directed = false) {
    vector <vector <int>> AdjList(vertice);
    for (auto Edge : Edges) {
        int u = Edge[0];
        int v = Edge[1];
        AdjList[u].push_back(v);
        if (!Directed)
            AdjList[v].push_back(u);
    }
    return AdjList;
}

// BFS function for Adj-List
void BFS(vector <vector <int>>& ADJlist, int StartNode) {
    // Create a queue for BFS
    int numNodes = ADJlist.size();
    vector<bool> visited(numNodes, false);  // Initialize visited vector with false
    queue <int> q;

    // Mark the current node as visited and enqueue it
    visited[StartNode] = true;
    q.push(StartNode);

    //Iterate over the queue
    while(!q.empty()) {
        // Dequeue a vertex from queue and print it
        int currentNode = q.front();
        q.pop();
        cout<< currentNode << " ";

        // Get all adjacent vertices of the dequeued vertex
        // currentNode If an adjacent has not been visited,
        // then mark it visited and enqueue it
        for (int neighbor : ADJlist[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    // Edges of the graph
    vector<vector<int>> Edges = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}
    };

    int vertice = 7;  // Total number of vertices
    vector<vector<int>> AdjList = Create_AdjList(Edges, vertice);


    int StartNode = 0;  // Starting node for BFS

    cout << "BFS starting from node " << StartNode << ": ";
    BFS(AdjList, StartNode);
    cout << endl;

    return 0;
}