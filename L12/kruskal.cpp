#include <iostream>
#include <vector>

using namespace std;

class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) { // n = vertex count
        parent.resize(n);
        rank.resize(n, 0);

        for (int i=0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int v) {
        if (v == parent[v]) {
            return v;
        }
        parent[v] = find(parent[v]);
        return parent[v];
    }

    void unite(int v1, int v2) {
        v1 = find(v1);
        v2 = find(v2);

        if (v1 == v2) return; // in one set

        if (rank[v1] < rank[v2]) {
            parent[v1] = v2;
        } else if (rank[v2] < rank[v1]) {
            parent[v2] = v1;
        } else {
            parent[v2] = v1;
            rank[v1]++;
        }
    }

    void display() {
        for (int x: parent) {
            cout << x << " "; 
        }
        cout << endl;
    }
};

struct Edge {
    int v, u, w;
};

bool comparator(Edge& e1, Edge& e2) {
    return e1.w < e2.w;
}

int kruskal(vector<Edge> &edges, int n) {
    sort(edges.begin(), edges.end(), comparator); 
    DSU dsu(n);

    int cost = 0;
    vector<Edge> mst;

    for (Edge &e: edges) {
        if (dsu.find(e.v) != dsu.find(e.u)) {
            dsu.unite(e.v, e.u);
            cost += e.w;
            mst.push_back(e);
        }
    }

    for (Edge &e: mst) {
        cout << e.v << " -- " << e.u << " with weight =  " << e.w << endl;
    }

    return cost;
}

int main() {
    // DSU dsu(4);



    // dsu.unite(0, 1);
    // dsu.unite(1, 3);

    // dsu.display();

    vector<Edge> edges;

    edges.push_back({0, 1, 13});
    edges.push_back({0, 2, 12});
    edges.push_back({1, 2, 3});
    edges.push_back({1, 3, 14});
    edges.push_back({2, 3, 9});

    cout << kruskal(edges, 4) << endl;

    return 0;
}