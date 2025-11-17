#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool dfsRec(int v, map<int, vector<int>> &adj, vector<bool> &visited, vector<bool> &ancestor)
{
    if (ancestor[v])
        return true;
    if (visited[v])
        return false;

    visited[v] = true;
    ancestor[v] = true;

    for (int i = 0; i < adj[v].size(); ++i)
    {
        int u = adj[v][i];
        if (dfsRec(u, adj, visited, ancestor))
            return true;
    }
    ancestor[v] = false;
    return false;
}

bool dfs(map<int, vector<int>> &adj, int numCourses)
{
    vector<bool> visited(numCourses, false);
    vector<bool> ancestors(numCourses, false);

    for (int v = 0; v < numCourses; ++v)
    {
        if (dfsRec(v, adj, visited, ancestors))
        {
            return true;
        }
    }
    return false;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    if (prerequisites.empty())
        return true;
    map<int, vector<int>> adj;
    for (int i = 0; i < prerequisites.size(); ++i)
    {
        int a_i = prerequisites[i][0];
        int b_i = prerequisites[i][1];
        adj[b_i].push_back(a_i);
    }
    return !dfs(adj, numCourses);
}

int main()
{
    int numCourses = 2;
    // vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    vector<vector<int>> prerequisites = {{1, 0}};

    cout << canFinish(numCourses, prerequisites) << endl;

    return 0;
}
