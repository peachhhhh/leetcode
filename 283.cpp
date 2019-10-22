#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//双指针，操作数最少
void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        while (i < n && nums[i] != 0)
        {
            i++;
        }
        while (j < n && (j < i || nums[j] == 0))
        {
            j++;
        }
    }
}

void test()
{
}

int main()
{
    test();
    return 0;
}