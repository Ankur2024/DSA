#include <bits/stdc++.h>

using namespace std;

void createAdjMatrix(vector<vector<int>> &adj, vector<pair<int, int>> graph){
    for(int i=0;i<graph.size();i++){
        int u = graph[i].first;
        int v = graph[i].second;
        adj[u][v] = 1;
    }
}

void printAdjMatrix(vector<vector<int>> &adj) {
    for (int i = 0; i < adj.size(); i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    int node;
    cout << "Enter the number of nodes" << endl;
    cin >> node;
    int edges;
    cout << "Enter the number of edges" << endl;
    cin >> edges;

    cout << "Give the edges between node" << endl;
    vector<pair<int, int>> graph(edges);
    for(int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        graph[i] = make_pair(u, v);
    }

    vector<vector<int>> adj(node, vector<int>(node, 0));

    createAdjMatrix(adj, graph);

    printAdjMatrix(adj);

    return 0;
}