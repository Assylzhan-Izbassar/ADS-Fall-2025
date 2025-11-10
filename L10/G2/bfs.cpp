#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(int start, vector<vector<int>> adj) {
    vector<int> visited(adj.size(), false);
    queue<int> q;
    vector<int> dist(adj.size(), 0);

    visited[start] = true;
    q.push(start);

    while(!q.empty()) {
        int v = q.front();
        cout << v << " ";
        q.pop();

        for (int i=0; i<adj[v].size(); ++i) {
            int u = adj[v][i];
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
                dist[u] = dist[v] + 1;
            }
        }
    }
    cout << endl;

    return dist;
}

int main() {
    vector<vector<int>> adj = {
        {1, 2},
        {0, 2, 3},
        {0, 1, 4},
        {1, 4},
        {2, 3}
    };
    int k = 2;
    vector<int> dist_starting_from_k = bfs(k, adj);

    for (int i=0; i<dist_starting_from_k.size(); ++i) {
        cout << dist_starting_from_k[i] << " ";
    }
    cout << endl;

    return 0;
}