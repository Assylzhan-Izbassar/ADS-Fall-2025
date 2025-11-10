#include <iostream>
#include <vector>

using namespace std;

int main() {
    // int n = 4;
    // vector<vector<int>> mat(n, vector<int>(n, 0));

    // for (int i=0; i<mat.size(); ++i) {
    //     for (int j=0; j<mat[i].size(); ++j) {
    //         cin >> mat[i][j];
    //     }
    // }
    vector<vector<int>> mat = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {1, 1, 1, 1, 0}
    };


    for (int i=0; i<mat.size(); ++i) {
        for (int j=0; j<mat[i].size(); ++j) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}