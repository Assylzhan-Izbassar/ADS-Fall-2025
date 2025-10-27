#include <iostream>
#include <vector>

using namespace std;

int charToInt(char c) {
    return c - 'a' + 1;
}

vector<int> rabinKarp(string& text, string& pattern) {
    int p = 31;
    long long mod = 1e9+7;

    int n = text.size();
    int m = pattern.size();

    vector<long long> p_pow(max(n, m));
    p_pow[0] = 1;
    for (int i=1; i < p_pow.size(); ++i) {
        p_pow[i] = (p_pow[i-1] * p) % mod;
    }

    // text hash calculation
    vector<long long> hashText(n+1, 0);
    for (int i=0; i < hashText.size(); ++i) {
        hashText[i+1] = hashText[i] + (charToInt(text[i]) * p_pow[i]) % mod;
    }

    // pattern hash calculation
    long long hashPattern = 0;
    for (int i=0; i < m; ++i) {
        hashPattern += (charToInt(pattern[i]) * p_pow[i]) % mod;
    }

    vector<int> occurance;
    
    for (int i=0; i < n - m + 1; ++i) {
        long long currHash = (hashText[i+m] - hashText[i] + mod) % mod;

        if (currHash == hashPattern * p_pow[i]) {
            occurance.push_back(i);
        }
    }
    return occurance;
}

int main() {

    string text = "abbabba";
    string pattern = "bb";

    vector<int> occurance = rabinKarp(text, pattern);

    for (int i=0; i<occurance.size(); ++i) {
        cout << occurance[i] << " ";
    }
    cout << endl;

    return 0;
}