#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<int>> create_AdjMatrix(const vector<vector<int>>& Edges, bool Directed = false) {
    // Find the number of vertices and create a mapping
    set<int> vertices_set;
    for (const auto& edge : Edges) {
        vertices_set.insert(edge[0]);
        vertices_set.insert(edge[1]); 
    }

    vector<int> vertices(vertices_set.begin(), vertices_set.end());
    map<int, int> vertex_index;
    for (size_t i = 0; i < vertices.size(); ++i) {
        vertex_index[vertices[i]] = i;
    }

    int Vertex = vertices.size();
    vector<vector<int>> AdjMatrix(Vertex, vector<int>(Vertex, 0));

    for (const auto& edge : Edges) {
        int u = vertex_index[edge[0]];
        int v = vertex_index[edge[1]];
        int weight = edge[2];
        AdjMatrix[u][v] = weight;
        if (!Directed) {
            AdjMatrix[v][u] = weight;
        }
    }

    return AdjMatrix;
}

void print_AdjMatrix(const vector<vector<int>>& AdjMatrix) {
    for (const auto& row : AdjMatrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> Edges = {
        {0, 1, 7},
        {0, 2, 3},
        {1, 2, 1},
        {1, 3, 4}
    };

    vector<vector<int>> AdjMatrix = create_AdjMatrix(Edges);
    print_AdjMatrix(AdjMatrix);

    return 0;
}
