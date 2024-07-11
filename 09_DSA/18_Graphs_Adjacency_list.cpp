#include <iostream>
#include <vector>
#include <list>

class Graph {
public:
    enum GraphType { DIRECTED, UNDIRECTED };
    
    Graph(int vertices, GraphType type);
    void addEdge(int src, int dest);
    void printGraph();

private:
    int vertices; // Number of vertices
    GraphType graph; // Type of graph (directed or undirected)
    std::vector<std::list<int>> adjList; // Adjacency list
};

// Constructor
Graph::Graph(int vertices, GraphType type) {
    this->vertices = vertices;
    this->graph = type;
    adjList.resize(vertices);
}

// Function to add an edge to the graph
void Graph::addEdge(int src, int dest) {
    adjList[src].push_back(dest);
    if (graph == UNDIRECTED) {
        adjList[dest].push_back(src);
    }
}

// Function to print the adjacency list representation of the graph
void Graph::printGraph() {
    for (int i = 0; i < vertices; ++i) {
        std::cout << "Vertex " << i << ":";
        for (auto x : adjList[i]) {
            std::cout << " -> " << x;
        }
        std::cout << std::endl;
    }
}

int main() {
    // Create a directed graph with 5 vertices
    Graph directedGraph(5, Graph::DIRECTED);

    // Add edges to the directed graph
    directedGraph.addEdge(0, 1);
    directedGraph.addEdge(0, 4);
    directedGraph.addEdge(1, 2);
    directedGraph.addEdge(1, 3);
    directedGraph.addEdge(1, 4);
    directedGraph.addEdge(2, 3);
    directedGraph.addEdge(3, 4);

    std::cout << "Directed Graph:" << std::endl;
    directedGraph.printGraph();

    // Create an undirected graph with 5 vertices
    Graph undirectedGraph(5, Graph::UNDIRECTED);

    // Add edges to the undirected graph
    undirectedGraph.addEdge(0, 1);
    undirectedGraph.addEdge(0, 4);
    undirectedGraph.addEdge(1, 2);
    undirectedGraph.addEdge(1, 3);
    undirectedGraph.addEdge(1, 4);
    undirectedGraph.addEdge(2, 3);
    undirectedGraph.addEdge(3, 4);

    std::cout << "\nUndirected Graph:" << std::endl;
    undirectedGraph.printGraph();

    return 0;
}
