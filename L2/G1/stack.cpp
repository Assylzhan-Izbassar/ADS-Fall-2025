#include <iostream>
#include <stack>

using namespace std;

int main() {

    stack<char> st;

    string s;
    cin >> s;

    size_t cnt = 0;

    // solution
    for (size_t i=0; i<s.size(); ++i) {
        // if (st.empty()) {
        //     st.push(s[i]); 
        // }
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
            cnt++;
        } else {
            char top = st.top();
            if (top == '(' && s[i] == ')') {
                st.pop();
                cnt++;
            } else if (top == '{' && s[i] == '}') {
                st.pop();
                cnt++;
            } else if (top == '[' && s[i] == ']') {
                st.pop();
                cnt++;
            }
            // empty
            // push
            // push
        }
    }

    if (cnt == s.size()) {
        cout << "YES!";
    } else {
        cout << "NO!";
    }
    cout << endl;

    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}