#include <iostream>
#include <vector>

using namespace std;

vector<int> bfs(int start, vector<vector<int>> adj)
{
    vector<int> visited(adj.size(), 0);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (int i = 0; i < adj[v].size(); ++i)
        {
            int u = adj[v][i];
            if (!visited[u])
            {
                visited[u] = true;
                q.push(u);
            }
        }
    }
    return visited;
}

int main()
{
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1},
    };

    int n = isConnected.size();
    vector<vector<int>> adj(n);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (isConnected[i][j] == 1)
            {
                adj[i].push_back(j);
            }
        }
    }

    int provinces = 0;
    vector<int> totalVisited(adj.size(), 0);
    int k = 0;

    while (true)
    {
        vector<int> visited = bfs(k, adj);
        provinces++;
        int prod = 1;
        for (int i = 0; i < visited.size(); ++i)
        {
            totalVisited[i] += visited[i];
            prod *= totalVisited[i];
        }
        if (prod == 1)
        {
            break;
        }
        for (int i = 0; i < totalVisited.size(); ++i)
        {
            if (totalVisited[i] == 0)
            {
                k = i;
            }
        }
    }

    cout << provinces << endl;

    return 0;
}