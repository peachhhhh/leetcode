#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findUnsortedSubarray(vector<int> &nums)
{
    int l = -1, r = -2;
    int n = nums.size();
    int mmax = nums[0], mmin = nums[n - 1];
    for (int i = 0; i < n; i++)
    {
        mmax = max(mmax, nums[i]);
        mmin = min(mmin, nums[n - i - 1]);
        if (nums[i] < mmax) //从左往右找，直到找不到比前面的最大值小的数
        {
            r = i;
        }
        if (nums[n - i - 1] > mmin) //从右往左找，直到找不到比后面的最小值大的数
        {
            l = n - i - 1;
        }
    }
    return r - l + 1;
}

void test()
{
}

int main()
{
    test();
    return 0;
}