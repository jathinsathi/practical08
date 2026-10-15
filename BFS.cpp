#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Class representing an undirected graph using an Adjacency List
class Graph {
    int numVertices;
    vector<vector<int>> adjList;

public:
    // Constructor
    Graph(int vertices) {
        numVertices = vertices;
        adjList.resize(vertices);
    }

    // Add an edge to the undirected graph
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Remove this line if you need a directed graph
    }

    // Function to perform BFS traversal from a given source vertex
    void performBFS(int startVertex) {
        // Track visited vertices to avoid processing a node multiple times
        vector<bool> visited(numVertices, false);
        
        // Create a queue for BFS operations
        queue<int> q;

        // Mark the starting node as visited and enqueue it
        visited[startVertex] = true;
        q.push(startVertex);

        cout << "BFS Traversal starting from vertex " << startVertex << ": ";

        while (!q.empty()) {
            // Dequeue a vertex from the front and print it
            int currentVertex = q.front();
            q.pop();
            cout << currentVertex << " ";

            // Explore all adjacent neighbors of the current vertex
            for (int neighbor : adjList[currentVertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    // Create a graph with 6 vertices (labeled 0 to 5)
    Graph g(6);

    // Add connections/edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    // Execute BFS from root vertex 0
    g.performBFS(0);

    return 0;
}
