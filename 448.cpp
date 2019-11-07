#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

vector<int> findDisappearedNumbers(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        while (nums[nums[i] - 1] != nums[i])
        {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != i + 1)
        {
            res.push_back(i + 1);
        }
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