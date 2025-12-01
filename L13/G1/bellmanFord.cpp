#include <iostream>
#include <vector>

using namespace std;

#define INF 1e9

vector<int> bellmanFord(int src, vector<vector<int>> &edges, int V) {
    vector<int> dist(V, INF);
    dist[src] = 0;

    for (int i=0; i < V; ++i) {
        for (vector<int> &edge: edges) {
            int u = edge[0];
            int v = edge[1]; 
            int w = edge[2];

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                if (i == V - 1) return {-1};
                dist[v] = dist[u] + w;
            }
        }
    }
    return dist;
}


int main() {
    int V = 5;

    vector<vector<int>> edges = {
        {0, 1, 5},
        {1, 2, 1},
        {1, 3, 2},
        {2, 4, 1},
        {4, 3, -1}
    };

    vector<int> dist = bellmanFord(0, edges, V);

    for (int d: dist) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}