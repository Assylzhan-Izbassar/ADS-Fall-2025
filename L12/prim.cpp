#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii; // weight, vertex

int prim(int start, vector<vector<pii>>& adj, int n) {
    vector<bool> visited(n, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, start});

    int cost = 0;
    vector<pii> mst;

    while(!pq.empty()) {
        pii v = pq.top();
        pq.pop();

        if (visited[v.second]) continue;

        visited[v.second] = true;

        if (v.first != 0) {
            cost += v.first;
            mst.push_back({v.second, v.first});
        }

        for (int i=0; i < adj[v.second].size(); ++i) {
            pii u = adj[v.second][i];
            int to = u.first;
            int weight = u.second;
            
            if (!visited[to]) {
                pq.push({weight, to});
            }
        }
    }

    int i = 0;
    for (pii v: mst) {
        cout << i << " " << v.first << " " << v.second << endl; 
        i++;
    }

    return cost;
}


int main() {

    vector<vector<pii>> adj(4);

    adj[0].push_back({1, 13});
    adj[1].push_back({0, 13});

    adj[0].push_back({2, 12});
    adj[2].push_back({0, 12});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 14});
    adj[3].push_back({1, 14});
    
    adj[2].push_back({3, 9});
    adj[3].push_back({2, 9});

    cout << prim(0, adj, 4) << endl;

    return 0;
}