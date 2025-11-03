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

vector<int> kmp(string& pat, string& text) {
    vector<int> result;

    // 1. Preprocessing
    vector<int> patLps = computeLPS(pat);
    
    // 2. Matching
    int n = text.size();
    int m = pat.size();

    int i = 0, j = 0;

    while (i < n) {
        if (pat[j] == text[i]) { // case 1 
            j++;
            i++;

            if (j == m) {
                result.push_back(i - j);
                j = patLps[j - 1];
            }
        } else {
            if (j == 0) { // case 2
                i++;
            } else {
                j = patLps[j - 1];
            }
        }
    }
    return result;
}

int main() {

    string pat = "ababaa";
    string text = "ababaababaacdbababaa";
    
    vector<int> idxMatches = kmp(pat, text);

    for (int i=0; i<idxMatches.size(); ++i) {
        cout << idxMatches[i] << " ";
    }
    cout << endl;
    
    return 0;
}