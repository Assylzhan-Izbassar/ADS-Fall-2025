#include <iostream>
#include <vector>

using namespace std;

bool dfsRec(int v, vector<vector<int>>& adj, vector<bool> visited, int parent) {
    // if (!visited[v]) return false; // no!
    visited[v] = true;

    for (int i=0; i < adj[v].size(); ++i) {
        int u = adj[v][i];
        if (!visited[u]) {
            if (dfsRec(u, adj, visited, v)) return true;
        } else if (parent != u) {
            return true;
        }
    }
    return false;
}

bool dfs(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> visited(V, false);

    for (int i=0; i < V; ++i) {
        if(dfsRec(i, adj, visited, -1)) return true;
    }
    return false;
}

int main() {
    vector<vector<int>> adj = {
        {1},
        {0}
    };

    cout << dfs(adj) << endl;

    return 0;
}