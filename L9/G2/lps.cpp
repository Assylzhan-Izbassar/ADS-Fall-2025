#include <iostream>

using namespace std;

vector<int> computeLPS(string& pat) {
    int n = pat.size();
    vector<int> lps(n, 0);

    int len = 0;
    int i = 1;

    while(i < n) {
        if (pat[len] == pat[i]) { // case 1
            len++; // we win
            lps[i] = len;
            i++;
        } else {
            if (len == 0) { // case 2
                lps[i] = 0;
                i++;
            } else {
                len = lps[len-1];
            }
        }
    } 
    return lps;
}

int main() {

    string pat = "ababcab";
    vector<int> patLps = computeLPS(pat);

    for (int i=0; i<patLps.size(); ++i) {
        cout << patLps[i] << " ";
    }
    cout << endl;
    
    return 0;
}