#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//动态规划,爬楼梯
int climbStairs(int n)
{
    int dp[n];
    dp[0] = 1;
    if (n > 1)
    {
        dp[1] = 2;
    }
    for (int i = 2; i < n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n - 1];
}

int main()
{
    cout << climbStairs(3) << endl;
    return 0;
}