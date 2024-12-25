#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int parent, vector<int>& disc, vector<int>& low, unordered_map<int, bool>& vis, vector<int>& ap, int& timer, unordered_map<int, list<int>>& adj) {
    vis[u] = true;
    disc[u] = low[u] = timer++;
    int child = 0;

    for (auto nbr : adj[u]) {
        if (nbr == parent) {
            continue;
        }
        if (!vis[nbr]) {
            dfs(nbr, u, disc, low, vis, ap, timer, adj);
            low[u] = min(low[u], low[nbr]);

            if (low[nbr] >= disc[u] && parent != -1) {
                ap[u] = 1; // Mark as articulation point
            }
            child++;
        } else {
            low[u] = min(low[u], disc[nbr]);
        }
    }

    // Special case for root node
    if (parent == -1 && child > 1) {
        ap[u] = 1;
    }
}

int main() {
    int n = 5; // Number of nodes
    int e = 5; // Number of edges
    vector<pair<int, int>> edges = {
        {0, 3}, {3, 4}, {0, 4}, {0, 1}, {1, 2}
    };

    // Adjacency list
    unordered_map<int, list<int>> adj;
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Initialize necessary variables
    int timer = 0;
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    unordered_map<int, bool> vis;
    vector<int> ap(n, 0);

    // Mark all nodes as unvisited
    for (int i = 0; i < n; i++) {
        vis[i] = false;
    }

    // Perform DFS for each connected component
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, -1, disc, low, vis, ap, timer, adj);
        }
    }

    // Print articulation points
    cout << "Articulation Points: ";
    for (int i = 0; i < n; i++) {
        if (ap[i] != 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
