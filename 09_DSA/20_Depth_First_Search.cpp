#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

//function to Create Adj-List 
vector<vector<int>> createAdjList(vector<vector<int>>& Edges, int Vertex, bool Directed = false) {
    vector<vector<int>> AdjList(Vertex);
    for (const auto& Edge : Edges) {
        int u = Edge[0];
        int v = Edge[1];
        AdjList[u].push_back(v);
        if (!Directed)
            AdjList[v].push_back(u);
    }
    return AdjList;
}

// Depth First Search for Adj-List
void DFS(vector<vector<int>>& AdjList, int starting_vertex, int numVertex) {
    vector<bool> visited(numVertex, false);
    stack<int> stack;

    stack.push(starting_vertex);
    while (!stack.empty()) {
        int crntVertex = stack.top();
        stack.pop();
        
        if (!visited[crntVertex]) {
            cout << crntVertex << " ";
            visited[crntVertex] = true;
        }

        for (const auto& neighbor : AdjList[crntVertex]) {
            if (!visited[neighbor]) {
                stack.push(neighbor);
            }
        }
    }
}

//function for no of vertex
int numberOfVertices(const vector<vector<int>>& Edges) {
    set<int> vertices;
    for (const auto& edge : Edges) {
        vertices.insert(edge[0]);
        vertices.insert(edge[1]);
    }
    return vertices.size();
}

//function for giving Vertex 
vector<int> getVerticesFromEdges(const vector<vector<int>>& Edges) {
    set<int> vertices_set;
    for (const auto& Edge : Edges) {
        vertices_set.insert(Edge[0]);
        vertices_set.insert(Edge[1]);
    }
    return vector<int>(vertices_set.begin(), vertices_set.end());
}

int main() {
    vector<vector<int>> Edges = {{0, 1}, {0, 4}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {3, 4}};
    int numVertex = numberOfVertices(Edges);

    cout << "Vertices of the graph:\n";
    vector<int> vertices = getVerticesFromEdges(Edges);
    for (int v : vertices) {
        cout << v << " ";
    }
    cout << "\n";

    vector<vector<int>> AdjList = createAdjList(Edges, numVertex);

    cout << "Depth First Traversal starting from vertex 3:\n";
    DFS(AdjList, 3, numVertex);

    return 0;
}
