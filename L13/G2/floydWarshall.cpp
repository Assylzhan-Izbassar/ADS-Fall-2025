#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e8;

void floydWarshall(vector<vector<int>>& dist, int V) {
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    int V = 6; 
    vector<vector<int>> dist = {
        {0, 4, 2, INF, INF, INF},
        {INF, 0, 5, 10, INF, INF},
        {INF, INF, 0, INF, 3, INF},
        {INF, INF, INF, 0, INF, 11},
        {INF, INF, INF, 4, 0, INF},
        {INF, INF, INF, INF, INF, 0}
    };

    floydWarshall(dist, V);

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF) cout << "~";
            else cout << dist[i][j];
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}
