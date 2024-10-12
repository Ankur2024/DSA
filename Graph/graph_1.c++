#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction) {
        adj[u].push_back(v);
        if (!direction) {
            adj[v].push_back(u);
        }
    }

    void printAdjList() {
        for (const auto& i : adj) {
            cout << i.first << " -> ";
            for (const auto& j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g;
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    cout << "Enter the number of edges: ";
    cin >> numEdges;
    cout << "Enter the edges (node1 node2): ";

    for (int i = 0; i < numEdges; i++) { 
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, false); 
    }

    cout << "Adjacency List: " << endl;
    g.printAdjList();
    return 0;
}
