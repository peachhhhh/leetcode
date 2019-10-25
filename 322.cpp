#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//动态规划
int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, -1);
    dp[0] = 0;
    for (int i = 0; i <= amount; i++)
    {
        for (auto c : coins)
        {
            if (i >= c && dp[i - c] != -1)
            {
                if (dp[i] == -1)
                {
                    dp[i] = dp[i - c] + 1;
                }
                else
                {
                    dp[i] = min(dp[i - c] + 1, dp[i]);
                }
            }
        }
    }
    return dp[amount];
}

//回溯，深度优先搜索，速度更快，空间更省
void dfs(vector<int> &coins, int amount, int count, int n, int &res)
{
    if (amount == 0)
    {
        res = min(res, count);
        return;
    }
    if (n == -1 || count + amount / coins[n] > res)
    {
        return;
    }
    for (int i = amount / coins[n]; i >= 0; i--)
    {
        dfs(coins, amount - coins[n] * i, count + i, n - 1, res);
    }
}

int coinChange2(vector<int> &coins, int amount)
{
    int res = INT32_MAX;
    sort(coins.begin(), coins.end());
    dfs(coins, amount, 0, coins.size() - 1, res);
    return res == INT32_MAX ? -1 : res;
}

void test()
{
    vector<int> v{1, 2, 5};
    int a = 11;
    cout << coinChange2(v, a) << endl;
}

int main()
{
    test();
    return 0;
}