#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> temp{};
vector<vector<int>> ans;

//回溯
void backtrack(vector<int> &nums, int i)
{
    if (i == nums.size())
    {
        return;
    }
    temp.push_back(nums[i]);
    ans.push_back(temp);
    backtrack(nums, i + 1);
    temp.pop_back();
    backtrack(nums, i + 1);
}
vector<vector<int>> subsets(vector<int> &nums)
{
    ans.push_back(temp);
    backtrack(nums, 0);
    return ans;
}
void test()
{
    vector<int> nums{1, 2, 3};
    subsets(nums);
}

//动态规划
vector<vector<int>> subsets2(vector<int> &nums)
{
    vector<vector<int>> dp;
    dp.push_back({});
    int tempLength;
    for (int i = 0; i < nums.size(); i++)
    {
        tempLength = dp.size();
        for (int j = 0; j < tempLength; j++)
        {
            dp.push_back(dp[j]);
            dp[j].push_back(nums[i]);
        }
    }
    return dp;
}
void test2()
{
    vector<int> nums{1, 2, 3};
    subsets2(nums);
}

int main()
{
    test();
    test2();
    return 0;
}