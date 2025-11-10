#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    int n = 5;
    vector<vector<int>> adj(n);

    string line;

    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        getline(cin, line);

        istringstream number(line);
        int num;
        while (number >> num) {
            // cout << num << " "; 
            adj[i].push_back(num);
        }
        // cout << endl;
    }

    for (int i=0; i < adj.size(); ++i) {
        cout << i << ": "; 
        for (int j=0; j < adj[i].size(); ++j) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    // vector<vector<int>> adj = {
    //     {1, 2},
    //     {0, 2, 3},
    //     {0, 1, 4} ,
    //     {1, 4},
    //     {2, 3},
    // };

    return 0;
}