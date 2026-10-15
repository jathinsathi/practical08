#include <iostream>
#include <vector>

using namespace std;

// Recursive helper function for DFS traversal
void dfsHelper(int node, const vector<vector<int>>& adj, vector<bool>& visited) {
    // Mark the current node as visited and print it
    visited[node] = true;
    cout << node << " ";

    // Recursively visit all unvisited neighbors
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsHelper(neighbor, adj, visited);
        }
    }
}

// Main DFS function that handles disconnected graphs
void dfs(const vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> visited(V, false);

    cout << "DFS Traversal: ";
    // Loop through all vertices to ensure disconnected components are visited
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            dfsHelper(i, adj, visited);
        }
    }
    cout << endl;
}

int main() {
    // Number of vertices in the graph
    int V = 6; 
    vector<vector<int>> adj(V);

    // Representing an undirected graph by adding edges
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 5};
    adj[3] = {1};
    adj[4] = {1};
    adj[5] = {2};

    // Run DFS traversal
    dfs(adj);

    return 0;
}
