#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 1e9
typedef pair<int, int> pii;

vector<int> dijkstra(int src, vector<vector<pii>>& adj, int V, vector<int>& parent) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(V, INF);

    dist[src] = 0;
    pq.emplace(0, src);

    while(!pq.empty()) {
        pii top = pq.top();
        pq.pop();

        int distanceU = top.first;
        int u = top.second;

        if (distanceU > dist[u]) continue;

        for (pii& node: adj[u]) {
            int v = node.first;
            int w = node.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(w, v);
                parent[v] = u;
            }
        }
    }
    return dist;
}

vector<int> restorePath(int start, int end, vector<int> parent) {
    vector<int> path;

    for (int v = end; v != -1; v = parent[v]) {
        path.push_back(v);
    }

    reverse(path.begin(), path.end());

    if (path[0] != start) return {};
    
    return path;
}

int main() {
    int V = 6;

    vector<vector<pii>> adj = {
        {{1, 4}, {2, 2}},
        {{2, 5}, {3, 10}},
        {{4, 3}}, 
        {{5, 11}},
        {{3, 4}},
        {}
    };
    
    vector<int> parent(V, -1);
    vector<int> dist = dijkstra(0, adj, V, parent);

    vector<int> path = restorePath(0, 3, parent);
    cout << "path: ";
    for (int p: path) {
        cout << p << " ";
    }
    cout << endl;

    cout << "dist: ";
    for (int d: dist) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}