#include <iostream>
#include <vector>
using namespace std;

//贪心算法简洁版
bool canJump2(vector<int> &nums)
{
    int far = 0;//能到达的最远点的下标
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > far)
        {
            return false;//如果当前遍历的点已经超过了能到达的最远点，说明无法跳到该点
        }
        far = max(far, i + nums[i]);//更新能到达的最远点下标
    }
    return true;
}

//贪心算法
int indexofmax(vector<int> &nums, int left, int right) //每次贪心地选择能走的最远的索引
{
    left++;
    int temp = left;
    while (left <= right)
    {
        if (left + nums[left] >= temp + nums[temp])
        {
            temp = left;
        }
        left++;
    }
    return temp;
}
bool canJump(vector<int> &nums)
{
    int i = 0;
    while (i < nums.size())
    {
        if (i + nums[i] >= nums.size() - 1)
        {
            return true;
        }
        if (nums[i] == 0)
        {
            return false;
        }
        i = indexofmax(nums, i, i + nums[i]);
    }
    return true;
}


int main()
{
    vector<int> v{4, 2, 0, 0, 1, 1, 4, 4, 4, 0, 4, 0};
    cout << canJump(v) << endl;
    cout << canJump2(v) << endl;
    return 0;
}