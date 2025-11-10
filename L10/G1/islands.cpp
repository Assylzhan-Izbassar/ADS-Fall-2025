#include <iostream>

using namespace std;

int bfs(int x, int y, vector<vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[x].size();

    int perimeter = 0;

    vector<vector<bool>> visited(row, vector<bool>(col, false));
    queue<pair<int, int>> q;

    visited[x][y] = true;
    q.push({x, y});

    int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty())
    {
        pair<int, int> v = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nx = v.first + d[i][0];
            int ny = v.second + d[i][1];

            if (nx >= row || ny >= col || nx < 0 || ny < 0 || grid[nx][ny] == 0)
            {
                perimeter++;
            }
            else if (!visited[nx][ny])
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return perimeter;
}

int islandPerimeter(vector<vector<int>> &grid)
{
    bool isStart = false;
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[i].size(); ++j)
        {
            if (grid[i][j] == 1)
            {
                return bfs(i, j, grid);
            }
        }
    }
    return 0;
}

int main()
{

    return 0;
}