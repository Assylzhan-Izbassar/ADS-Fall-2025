#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    int n_vertices = 5;
    vector<vector<int>> adj(n_vertices);

    string line;
    int number;

    for (int i=0; i < n_vertices; ++i) {
        cout << i << ": "; 
        getline(cin, line);
        istringstream ss(line);

        while (ss >> number) {
            adj[i].push_back(number);
        }
    }

    for (int i=0; i<adj.size(); ++i) {
        cout << i << ": ";
        for (int j=0; j < adj[i].size(); ++j) {
            cout << adj[i][j];
            if (j + 1 != adj[i].size()) cout << ", ";
        }
        cout << endl;
    }

    return 0;
}