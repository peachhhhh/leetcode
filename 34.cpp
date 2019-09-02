#include <iostream>
#include <vector>
using namespace std;

//二分查找，分别找头尾
vector<int> searchRange(vector<int> &nums, int target)
{
    if (nums.empty())
    {
        return {-1, -1};
    }
    vector<int> v;
    v.push_back(head(nums, target));
    v.push_back(tail(nums, target));
    return v;
}

int head(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    int mid = (left + right) / 2;
    while (left < right - 1)
    {
        if (nums[mid] < target)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
        mid = (left + right) / 2;
    }
    if (nums[left] == target)
    {
        return left;
    }
    if (nums[right] == target)
    {
        return right;
    }
    return -1;
}

int tail(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    int mid = (left + right) / 2;
    while (left < right - 1)
    {
        if (nums[mid] <= target)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
        mid = (left + right) / 2;
    }
    if (nums[right] == target)
    {
        return right;
    }
    if (nums[left] == target)
    {
        return left;
    }
    return -1;
}

int main()
{
    return 0;
}