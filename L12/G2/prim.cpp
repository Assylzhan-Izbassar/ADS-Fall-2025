#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii; // weight, vertex

struct Edge {
    int v, u, w; // w = weight;
};

int prim(int start, vector<vector<pii>> &adj, int n) {
    vector<bool> visited(n, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, start});

    int cost = 0;
    vector<pii> mst;

    while(!pq.empty()) {
        pii x = pq.top();
        pq.pop();

        int w = x.first;
        int v = x.second;

        if (visited[v]) continue;

        visited[v] = true;
        cost += w;
        
        if (w != 0) {
            mst.push_back({v, w});
        }

        for (int i=0; i < adj[v].size(); ++i) {
            pii y = adj[v][i];
            int u = y.first;
            int weight = y.second;

            if (!visited[u]) {
                pq.push({weight, u});
            }
        }
    }   

    for (int i=0; i < mst.size(); ++i) {
        cout << mst[i].first << " with weight = " << mst[i].second << endl;
    }

    return cost;

}

int main() {

    int n = 9;

    vector<Edge> edges;

    edges.push_back({0, 1, 4});
    edges.push_back({0, 7, 8});
    edges.push_back({1, 7, 11});
    edges.push_back({1, 2, 8});
    edges.push_back({2, 3, 7});
    edges.push_back({2, 8, 2});
    edges.push_back({2, 5, 4});
    edges.push_back({3, 5, 14});
    edges.push_back({3, 4, 9});
    edges.push_back({4, 5, 10});
    edges.push_back({5, 6, 2});
    edges.push_back({6, 7, 1});
    edges.push_back({6, 8, 6});
    edges.push_back({7, 8, 7});

    vector<vector<pii>> adj(n);

    for (Edge &e: edges) {
        adj[e.v].push_back({e.u, e.w});
        adj[e.u].push_back({e.v, e.w});
    }

    cout << prim(0, adj, n) << endl;

    return 0;
}