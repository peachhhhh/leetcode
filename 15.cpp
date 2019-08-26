#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//nums排序后，双指针
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    if (nums.empty())
    {
        return {};
    }
    sort(nums.begin(), nums.end());
    vector<int>::iterator it1 = nums.begin();
    vector<int>::iterator it2 = nums.begin() + 1;
    vector<int>::iterator it3 = nums.end() - 1;
    vector<int> temp = {nums[0] - 1, nums[0] - 1, nums[0] - 1};
    while (*it1 <= 0 && it1 < nums.end() - 2)
    {
        while (it2 < it3)
        {
            if (*it1 + *it2 + *it3 < 0)
            {
                it2++;
            }
            else if (*it1 + *it2 + *it3 > 0)
            {
                it3--;
            }
            else if (*it1 + *it2 + *it3 == 0)
            {
                if (*it1 != temp[0] || *it2 != temp[1])
                {
                    temp.clear();
                    temp.push_back(*it1);
                    temp.push_back(*it2);
                    temp.push_back(*it3);
                    ans.push_back(temp);
                }
                it2++;
                it3--;
            }
        }
        it1++;
        while (*it1 == *(it1 - 1) && *it1 <= 0 && it1 < nums.end() - 2)
        {
            it1++;
        }
        it2 = it1 + 1;
        it3 = nums.end() - 1;
    }
    return ans;
}

int main()
{
    vector<int> a = {3,0,-2,-1,1,2};
    cout << threeSum(a)[0][1] << endl;
    return 0;
}