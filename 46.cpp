#include <iostream>
#include <vector>
using namespace std;

//vector<int> temp;
vector<vector<int>> ans;
int buff;

//回溯算法
void backtrack(vector<int> &nums, int i)
{
    if (i == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int j = i; j < nums.size(); j++)
    {
        buff = nums[j];
        nums[j] = nums[i];
        nums[i] = buff;

        //temp.push_back(nums[j]);
        backtrack(nums, i + 1);
        //temp.pop_back();

        buff = nums[j];
        nums[j] = nums[i];
        nums[i] = buff;
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    backtrack(nums, 0);
    return ans;
}

int main()
{
    vector<int> nums{1, 2, 3};
    permute(nums);
    return 0;
}