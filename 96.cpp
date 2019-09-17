#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//动态规划，详见leetcode官方题解
int numTrees(int n)
{
    int dp[n + 1] = {0};
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}

void test()
{
}

int main()
{
    test();
    return 0;
}