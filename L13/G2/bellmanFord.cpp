#include <iostream>
#include <vector>

using namespace std;

#define INF 1e9

vector<int> bellmanFord(int src, vector<vector<int>>& edges, int V) {
    vector<int> dist(V, INF);
    dist[src] = 0;

    for (int i = 0; i < V; ++i) {
        for (vector<int> &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (dist[u] != INF && dist[v] > dist[u] + w) { // relaxation
                if (i == V - 1) return {-1};
                dist[v] = dist[u] + w;
            }
        }
    }
    return dist;
}

void print(vector<int> v) {
    for (int x: v) {
        cout << x << " ";
    }
    cout << endl;
}


int main() {
    int V = 6;

    vector<vector<int>> edges = {
        {0, 1, 4},
        {0, 2, 2},
        {1, 2, 5},
        {3, 1, -15},
        {2, 4, 3},
        {4, 3, 4},
        {3, 5, 11}
    };

    vector<int> dist = bellmanFord(0, edges, V);

    print(dist);

    return 0;
}