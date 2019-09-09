#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//动态规划，dp[i][j]表示word1的前i个字符转换成word2的前j个字符需要多少次操作
int minDistance(string word1, string word2)
{
    int m = word1.size(), n = word2.size();
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = j;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (word1[i - 1] != word2[j - 1])
            {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    return dp[m][n];
}

void test()
{
    string s1 = "zoolog", s2 = "zoog";
    cout << minDistance(s1, s2) << endl;
}

int main()
{
    test();
    return 0;
}