#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//动态规划
int maxCoins(vector<int> &nums)
{
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int len = 2; len < n; len++)
    {
        for (int i = 0; i + len < n; i++)
        {
            for (int k = i + 1; k < i + len; k++)
            {
                dp[i][i + len] = max(dp[i][i + len], nums[i] * nums[k] * nums[i + len] + dp[i][k] + dp[k][i + len]);
            }
        }
    }
    return dp[0][n - 1];
}

void test()
{
    vector<int> v{3, 1, 5, 8};
    cout << maxCoins(v) << endl;
}

int main()
{
    test();
    return 0;
}