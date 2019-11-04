#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//动态规划，dp[j]表示能否从nums[0]到nums[i]能否构成和为j，最后得到nums[n - 1]时的dp[sum]，即答案
bool canPartition(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }
    if (sum % 2 == 1)
    {
        return false;
    }
    sum = sum / 2;
    bool dp[sum + 1] = {true};
    for (int i = 1; i < n; i++)
    {
        for (int j = sum; j >= 0; j--)
        {
            if (j >= nums[i])
            {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
            else
            {
                break;
            }
        }
    }
    return dp[sum];
}

void test()
{
    vector<int> v{1, 2, 5};
    cout << canPartition(v) << endl;
}

int main()
{
    test();
    return 0;
}
