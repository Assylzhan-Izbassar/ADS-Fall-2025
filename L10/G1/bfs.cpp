#include <iostream>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

vector<int> bfs(int start, vector<vector<int>> adj) {
    vector<int> visited(adj.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    vector<int> dist(adj.size(), 0);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

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
        {0, 1, 4} ,
        {1, 4},
        {2, 3},
    };

    int k = 3;

    vector<int> dist_from_k = bfs(k, adj);

    for (int i=0; i < dist_from_k.size(); ++i) {
        cout << dist_from_k[i] << " ";
    }
    cout << endl;

    return 0;
}