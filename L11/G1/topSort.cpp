#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void topDFS(int v,
            vector<vector<int>>& adj,
            vector<bool>& visited,
            vector<int>& order) {
    visited[v] = true;

    for (int i=0; i < adj[v].size(); ++i) {
        int u = adj[v][i];
        if (!visited[u]) {
            topDFS(u, adj, visited, order);
        }
    }

    order.push_back(v);
}


void topSort(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    vector<int> order;

    for (int i=0; i < n; ++i) {
        if (!visited[i]) {
            topDFS(i, adj, visited, order);
        }
    }
    reverse(order.begin(), order.end());

    for (int i=0; i < order.size(); ++i) {
        cout << order[i] << " ";
    }
    cout << endl;
}

int main() {

    vector<vector<int>> adj = {{1}, {2}, {}, {2, 4}, {}};

    topSort(adj);
    
    return 0;
}