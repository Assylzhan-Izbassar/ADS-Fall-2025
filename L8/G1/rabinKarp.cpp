#include <iostream>
#include <vector>

using namespace std;

int charToInt(char c) {
    return c - 'a' + 1;
}

vector<int> rabinKarp(string const& s, string const& t) {
    int p = 31;
    long long mod = 1e9 + 7;

    int n = s.size();
    int m = t.size();

    vector<long long> p_pow(max(n, m));
    p_pow[0] = 1;
    for (int i=1; i < p_pow.size(); ++i) {
        p_pow[i] = (p_pow[i-1] * p) % mod;
    }

    vector<long long> h(m + 1, 0);
    for (int i=0; i < h.size(); ++i) {
        h[i+1] = (h[i] + charToInt(t[i]) * p_pow[i]) % mod; 
    }

    long long h_pattern = 0;

    for (int i=0; i < s.size(); ++i) {
        h_pattern = (h_pattern + charToInt(s[i]) * p_pow[i]) % mod;
    }

    vector<int> occurance;

    for (int i=0; i < m - n + 1; ++i) {
        long long currHash = (h[i+n] - h[i] + mod) % mod;
        if (currHash == (h_pattern * p_pow[i]) % mod) {
            occurance.push_back(i);
        }
    }
    return occurance;

}

int main() {

    string s, t;
    cin >> s >> t;

    vector<int> occurences = rabinKarp(s, t);

    cout << "Output:\n";

    for (int i=0; i<occurences.size(); ++i) {
        cout << occurences[i] << " ";
    }

    return 0;
}