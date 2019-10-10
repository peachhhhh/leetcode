#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//类似53题最大子序和，另外考虑到乘法带来的符号问题，每一步要同时更新最大值up最小值down
int maxProduct(vector<int> &nums)
{
    int up = nums[0], down = nums[0], ans = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        int tmp = down;
        down = min(nums[i], min(up * nums[i], down * nums[i]));
        up = max(nums[i], max(up * nums[i], tmp * nums[i]));
        ans = max(ans, up);
    }
    return ans;
}

void test()
{
}

int main()
{
    test();
    return 0;
}