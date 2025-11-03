#include <iostream>

using namespace std;

vector<int> computeLPS(string& pat) {
    int n = pat.size();
    vector<int> lps(n, 0);

    int len = 0;
    int i = 1;

    while (i < n) {
        if (pat[i] == pat[len]) { // case 1.
            len++;
            lps[i] = len;
            i++;
        } else { 
            if (len == 0) { // case 2.
                lps[i] = 0;
                i++;
            } else { // case 3: len > 0.
                len = lps[len - 1];
            }
        }
    }
    return lps;
}

int main() {

    string s = "ababaa";

    vector<int> lps = computeLPS(s);

    for(int i=0; i < lps.size(); ++i) {
        cout << lps[i] << " ";
    }
    cout << endl;
    
    return 0;
}