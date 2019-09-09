#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//动态规划,最小路径和
int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    int dp[m][n];
    dp[0][0] = grid[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j != 0)
            {
                dp[i][j] = dp[i][j - 1] + grid[i][j];
            }
            else if (i != 0 && j == 0)
            {
                dp[i][j] = dp[i - 1][j] + grid[i][j];
            }
            else if (i != 0 && j != 0)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
    }
    return dp[m - 1][n - 1];
}

int main()
{
    return 0;
}