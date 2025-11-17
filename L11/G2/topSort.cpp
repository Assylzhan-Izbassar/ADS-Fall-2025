#include <iostream>
#include <vector>

using namespace std;

void dfsRec(int v, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& order) {
    // if (visited[v]) {
    //     return;
    // }
    visited[v] = true;
    // cout << v << " "; 

    for (int i=0; i < adj[v].size(); ++i) {
        int u = adj[v][i];
        if (!visited[u]) dfsRec(u, adj, visited, order);
    }

    order.push_back(v);
}

void topSort(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> visited(V, false);
    vector<int> order;

    for (int i=0; i < V; ++i)
        if (!visited[i]) dfsRec(i, adj, visited, order);

    // reverse(order.begin(), order.end());
    for (int i=0; i < order.size(); ++i) {
        cout << order[i] << " ";
    }
    cout << endl;
}

int main() {

    vector<vector<int>> adj = {
        {1},
        {2},
        {},
        {2, 4},
        {}
    };

    topSort(adj);
    
    return 0;
}