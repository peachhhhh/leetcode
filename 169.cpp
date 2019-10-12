#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Boyer-Moore(摩尔)投票算法，时间复杂度o(n)，空间复杂度o(1)
int majorityElement(vector<int> &nums)
{
    int tmp = nums[0];
    int count = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (count == 0)
        {
            tmp = nums[i];
            count++;
        }
        else if (nums[i] != tmp)
        {
            count--;
        }
        else
        {
            count++;
        }
    }
    return tmp;
}

void test()
{
    vector<int> v{1, 1, 2, 3, 4};
    cout << majorityElement(v) << endl;
}

int main()
{
    test();
    return 0;
}