#include <iostream>
#include <vector>

using namespace std;

void dfsRec(int v, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[v] = true;
    
    cout << v << " "; 

    for (int i=0; i < adj[v].size(); ++i) {
        int u = adj[v][i]; // neighbor
        if (!visited[u]) {
            dfsRec(u, adj, visited);
        }
    }
}

void dfs(int start, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    dfsRec(start, adj, visited);
}

int main() {

    vector<vector<int>> adj = {
        {1, 2},
        {0, 2},
        {0, 1, 3, 4},
        {2},
        {2}
    };

    dfs(0, adj);

    cout << endl;
    
    return 0;
}