#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//bfs广度优先遍历
int numIslands(vector<vector<char>> &grid)
{
    if (grid.empty())
    {
        return 0;
    }
    int res = 0;
    queue<pair<int, int>> q;
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1')
            {
                res++;
                grid[i][j] = '0';
                q.push({i, j});
                while (!q.empty()) //从一个点开始，用队列实现广度优先遍历
                {
                    int f = q.front().first, s = q.front().second;
                    q.pop();
                    if (f - 1 >= 0 && grid[f - 1][s] == '1')
                    {
                        q.push({f - 1, s});
                        grid[f - 1][s] = '0';
                    }
                    if (f + 1 < m && grid[f + 1][s] == '1')
                    {
                        q.push({f + 1, s});
                        grid[f + 1][s] = '0';
                    }
                    if (s - 1 >= 0 && grid[f][s - 1] == '1')
                    {
                        q.push({f, s - 1});
                        grid[f][s - 1] = '0';
                    }
                    if (s + 1 < n && grid[f][s + 1] == '1')
                    {
                        q.push({f, s + 1});
                        grid[f][s + 1] = '0';
                    }
                }
            }
        }
    }
    return res;
}

void test()
{
    vector<vector<char>> grid{{'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'}};
    cout << numIslands(grid) << endl;
}

int main()
{
    test();
    return 0;
}