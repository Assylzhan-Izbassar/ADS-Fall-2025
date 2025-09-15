// stack
#include <iostream>
#include <stack>

using namespace std;

int main()
{

    string s;
    cin >> s;

    stack<char> st;

    for (int i = 0; i < s.size(); ++i)
    {
        // when we meet opened braces;
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        // when we meet closed braces;
        else
        {
            // while (st.empty() && i > 0) {
                char top = st.top();

                if (top == '(' && s[i] == ')') {
                    st.pop();
                    // i--;
                    // continue;
                } 
                if (top == '{' && s[i] == '}') {
                    st.pop();
                    // i--;
                    // continue;
                } 
                if (top == '[' && s[i] == ']') {
                    st.pop();
                    // i--;
                    // continue;
                } 
            // }
        }
    }

    if (st.empty())
    {
        cout << "YES!\n";
    }
    else
    {
        cout << "NO!\n";
    }

    return 0;
}