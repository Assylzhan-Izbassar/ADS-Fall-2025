#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> idxs;

    string s;
    cin >> s;

    int cnt[26];

    for (size_t i=0; i<26; ++i) {
        cnt[i] = 0;
    }

    for (size_t i=0; i<s.size(); ++i) {
        char letter = s[i] - 'a';
        cnt[letter]++;

        if (cnt[letter] == 1) {
            idxs.push(i);
        }

        while (!idxs.empty() && (cnt[s[idxs.front()] - 'a'] > 1 && s[idxs.front()] == s[i])) {
            idxs.pop();
        }
    }

    if (idxs.empty()) {
        cout << -1 << endl;
    } else {
        cout << idxs.front() << endl;
    }

    // for (size_t i=0; i<26; ++i) {
    //     cout << cnt[i] << " ";
    // }

    // cout << endl;


    return 0;
}