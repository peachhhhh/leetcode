#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//分治，修改过后的快速排序，找到第k个就返回
int recursion(vector<int> &nums, int l, int f, int k)
{
    int i = l, j = f;
    int pivot = nums[(i + j)/2];
    nums[(i + j)/2] = nums[i];
    nums[i] = pivot;
    while (i < j)
    {
        while (i < j && nums[j] <= pivot)
        {
            j--;
        }
        nums[i] = nums[j];
        while (i < j && nums[i] >= pivot)
        {
            i++;
        }
        nums[j] = nums[i];
    }
    nums[i] = pivot;
    if (k - 1 > i)
    {
        return recursion(nums, i + 1, f, k);
    }
    else if (k - 1 < i)
    {
        return recursion(nums, l, i - 1, k);
    }
    else
    {
        return pivot;
    }
}

int findKthLargest(vector<int> &nums, int k)
{
    return recursion(nums, 0, nums.size() - 1, k);
}

void test()
{
}

int main()
{
    test();
    return 0;
}