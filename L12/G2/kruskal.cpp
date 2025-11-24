#include <iostream>
#include <vector>

using namespace std;

class DSU {
private:
    vector<int> parent;
    vector<int> rank; // height of the tree set;
public:
    DSU(int n) { // vertex count
        parent.resize(n);
        rank.resize(n, 0);

        for (int i=0; i<n; ++i) {
            parent[i] = i;
        }
    }

    int find(int v) {
        if (v == parent[v]) { // we find the root
            return v;
        }
        parent[v] = find(parent[v]);
        return parent[v];
    }

    void unite(int v1, int v2) { // v1 = 2, v2 = 3 -> root = 0
        v1 = find(v1); // set 1
        v2 = find(v2); // set 2

        if (v1 == v2) return;

        // parent[v1] = v2; // usual union
        if (rank[v1] < rank[v2]) {
            parent[v1] = v2;
        } else if (rank[v2] < rank[v1]) {
            parent[v2] = v1;
        } else {
            parent[v2] = v1;
            rank[v1]++;
        }
    }
};

struct Edge {
    int v, u, w; // w = weight;
};

bool comp(Edge &e1, Edge &e2) {
    return e1.w < e2.w;
}

int kruskal(vector<Edge> edges, int n) { // n = vertex count
    sort(edges.begin(), edges.end(), comp);
    DSU dsu(n);

    int cost = 0;
    vector<pair<pair<int, int>, int>> mst;

    for (Edge &e: edges) {
        if (dsu.find(e.v) != dsu.find(e.u)) {
            dsu.unite(e.v, e.u);
            cost += e.w;
            mst.push_back({{e.v, e.u}, e.w});
        }
    }

    for (int i=0; i < mst.size(); ++i) {
        cout << mst[i].first.first << " -- " << mst[i].first.second<< " with weight = " << mst[i].second << endl; 
    }

    return cost;
}

int main() {
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

    cout << kruskal(edges, 9) << endl;

    return 0;
}