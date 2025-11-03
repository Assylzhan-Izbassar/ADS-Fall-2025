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

vector<int> search(string& text, string& pat) {
    vector<int> patLps = computeLPS(pat);

    int n = text.size();
    int m = pat.size();

    int i = 0;
    int j = 0;

    vector<int> result;

    while(i < n) {
        if (pat[j] == text[i]) {
            i++;
            j++;

            if (j == m) {
                result.push_back(i - j); // index of starting the pattern inside the text
                j = patLps[j-1]; // important part of backtracking.
            }
        } else {
            if (j == 0) {
                i++;
            } else {
                j = patLps[j - 1];
            }
        }
    }

    return result;
}

int main() {

    string s = "ababaa";
    string text = "ababaababaabca";

    // vector<int> lps = computeLPS(s);

    // for(int i=0; i < lps.size(); ++i) {
    //     cout << lps[i] << " ";
    // }
    // cout << endl;

    vector<int> matchedIdx = search(text, s);

    for (int i=0; i<matchedIdx.size(); ++i) {
        cout << matchedIdx[i] << " ";
    }
    cout << endl;
    
    return 0;
}