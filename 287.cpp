#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//对值域二分查找
int findDuplicate(vector<int> &nums)
{
    int n = nums.size() - 1;
    int l = 1, r = n;
    int mid, count = 0;
    while (l < r)
    {
        count = 0;
        mid = (l + r) / 2;
        for (int i = 0; i <= n; i++)
        {
            if (nums[i] <= mid && nums[i] >= l)
            {
                count++;
            }
        }
        if (count > mid - l + 1)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return r;
}

void test()
{
    vector<int> v{3, 1, 3, 4, 2};
    cout << findDuplicate(v) << endl;
}

int main()
{
    test();
    return 0;
}