#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//动态规划
int lengthOfLIS(vector<int> &nums)
{
    vector<int> dp(nums.size(), 1);
    int res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    return res;
}

void test()
{
}

int main()
{
    test();
    return 0;
}
