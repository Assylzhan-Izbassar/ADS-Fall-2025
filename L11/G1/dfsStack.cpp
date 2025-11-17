#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int start, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    stack<int> st;

    st.push(start);

    while(!st.empty()) {
        int v = st.top();
        st.pop();
        
        if (!visited[v]) {
            visited[v] = true;
            cout << v << " ";
        }

        for (int i=adj[v].size(); i >= 0; --i) {
            int u = adj[v][i];
            if (!visited[u]) {
                st.push(u);
            }
        }

    }
}

int main() {

    vector<vector<int>> adj = {
        {1, 2},
        {0, 2},
        {0, 1, 3, 4},
        {2},
        {2}
    };

    dfs(0, adj);

    cout << endl;
    
    return 0;
}