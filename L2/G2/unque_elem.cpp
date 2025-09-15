#include <iostream>
#include <queue>

using namespace std;

int main() {
    string s;
    cin >> s;

    int cnt[26];

    for (int i=0; i<26; ++i) {
        cnt[i] = 0;
    }

    queue<int> q;

    for (int i=0; i<s.size(); ++i) {
        int letter_idx = s[i] - 'a'; // ascii
        cnt[letter_idx]++;

        if (!q.empty()) {
            int idx = q.front();

            if (s[idx] == s[i]) {
                q.pop();
                idx = q.front();
                int letter_idx = s[idx] - 'a';

                while (!q.empty() && (cnt[letter_idx] > 1)) {
                    q.pop();
                    idx = q.front();
                    letter_idx = s[idx] - 'a';
                }
            }
        }

        if (cnt[letter_idx] < 2) {
            q.push(i);
        }
    }

    if (q.empty()) {
        cout << -1;
    } else {
        cout << q.front(); 
    }
    cout << endl;

    return 0;
}