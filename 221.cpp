#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//动态规划，用dp数组来保存  若当前点为正方形的右下角时的最大正方形的边长  每次更新dp时，由上点，左点，左上点来决定当前点的dp值
int maximalSquare(vector<vector<char>> &matrix)
{
    if (matrix.size() == 0)
    {
        return 0;
    }
    int ans = 0;
    int dp[matrix.size()][matrix[0].size()];
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (i == 0 || j == 0 || matrix[i][j] == '0')
            {
                dp[i][j] = matrix[i][j] - '0';
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    return ans * ans;
}

void test()
{
}

int main()
{
    test();
    return 0;
}