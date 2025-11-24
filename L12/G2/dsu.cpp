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


int main() {
    return 0;
}