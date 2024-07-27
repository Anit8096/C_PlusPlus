#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

int numofVertex(const vector<vector<int>>& Edges) {
    set<int> numVertex;
    for (const auto& edge : Edges) {
        numVertex.insert(edge[0]);
        numVertex.insert(edge[1]);
    }
    return numVertex.size();
}

vector<vector<int>> create_AdjMatrix(const vector<vector<int>>& Edges, bool Directed = false) {
    int Vertex = numofVertex(Edges);
    vector<vector<int>> AdjMatrix(Vertex, vector<int>(Vertex, 0));

    for (const auto& edge : Edges) {
        int u = edge[0];
        int v = edge[1];
        AdjMatrix[u][v] = 1;
        if (!Directed)
            AdjMatrix[v][u] = 1;
    }

    return AdjMatrix;
}

void DFS(int startnode, const vector<vector<int>>& AdjMatrix) {
    int numVertex = AdjMatrix.size();
    vector<bool> visited(numVertex, false);
    stack<int> stack;
    stack.push(startnode);

    while (!stack.empty()) {
        int vertex = stack.top();
        stack.pop();

        if (!visited[vertex]) {
            cout << vertex << " ";
            visited[vertex] = true;
        }

        for (vector<int>::size_type i = 0; i < AdjMatrix[vertex].size(); ++i) {
            if (AdjMatrix[vertex][i] == 1 && !visited[i]) {
                stack.push(i);
            }
        }
    }
}

int main() {
    vector<vector<int>> Edges = {
        {0, 1},
        {0, 4},
        {1, 2},
        {1, 3},
        {1, 4},
        {2, 3},
        {3, 4},
        {4, 5},
        {5, 6},
        {5, 7},
        {6, 7},
        {6, 8},
        {7, 8},
        {8, 9},
        {9, 10},
        {9, 11},
        {10, 11},
        {10, 12},
        {11, 12},
        {12, 13},
        {13, 14},
        {13, 15},
        {14, 15},
        {14, 16},
        {15, 16}
    };

    vector<vector<int>> AdjMatrix = create_AdjMatrix(Edges);

    cout << "DFS starting from vertex 10: ";
    DFS(10, AdjMatrix);
    cout << endl;

    return 0;
}
