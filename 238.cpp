#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//每个位置的乘积等于左积乘右积，遍历一次即可
vector<int> productExceptSelf(vector<int> &nums)
{
    int l = 1, r = 1;
    int n = nums.size();
    vector<int> res(n, 1);
    for (int i = 0; i < n; i++)
    {
        res[i] *= l;
        l *= nums[i];
        res[n - i - 1] *= r;
        r *= nums[n - i - 1];
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