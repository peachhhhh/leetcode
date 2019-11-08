#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//无剪枝的回溯，o(2^n)
void dfs(vector<int> &nums, long int S, int i, int &res)
{
    if (i == nums.size())
    {
        if (S == 0)
        {
            res++;
        }
        return;
    }
    dfs(nums, S - nums[i], i + 1, res);
    dfs(nums, S + nums[i], i + 1, res);
}

int findTargetSumWays(vector<int> &nums, long int S)
{
    int res = 0;
    dfs(nums, S - nums[0], 1, res);
    dfs(nums, S + nums[0], 1, res);
    return res;
}

//动态规划
int findTargetSumWays2(vector<int> &nums, int S)
{
    int sum = 0;
    for (auto &n : nums)
    {
        sum += n;
    }
    if (sum < S || (sum + S) % 2 == 1) //先排除无解的情况
    {
        return 0;
    }
    int positiveNumSUM = (sum + S) / 2; //表示满足题意的所有正数的和
    vector<int> dp(positiveNumSUM + 1, 0);
    dp[0] = 1;
    for (auto &n : nums)
    {
        for (int j = positiveNumSUM; j >= n; j--)
        {
            dp[j] += dp[j - n]; //dp[j]表示，到前一个点时，和为j的答案种数
        }
    }
    return dp[positiveNumSUM];
}

void test()
{
}

int main()
{
    test();
    return 0;
}