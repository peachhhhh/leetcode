#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//简单的动态规划
int uniquePaths(int m, int n)
{
    //vector<vector<int>> dp(m, vector<int>(n));
    int dp[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0 || i == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
    }
    return dp[m - 1][n - 1];
}

int main()
{
    cout << uniquePaths(4, 3) << endl;
    return 0;
}