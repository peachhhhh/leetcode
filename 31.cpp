#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
求下一个更大的字典序：从右往左遍历，直到发现数字降低了，如“???2431”，则2后面取逆，得“???2134”，
然后在2后面的上升序列中找到第一个比2大的数，与2交换位置得到最后结果。
*/
void nextPermutation(vector<int> &nums)
{
    if(nums.size() == 1 || nums.size() == 0){
        return;
    }
    vector<int>::iterator it = nums.end() - 1;
    while (it > nums.begin() && *(it - 1) >= *it)
    {
        it--;
    }
    reverse(it, nums.end());
    if (it == nums.begin())
    {
        return;
    }
    int left = it - nums.begin() - 1;
    int right = nums.size() - 1;
    int mid = (left + right) / 2;
    while (left < right)
    {
        if (nums[mid] <= *(it - 1))
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
        mid = (left + right) / 2;
    }
    int temp = nums[mid];
    nums[mid] = *(it - 1);
    *(it - 1) = temp;
    return;
}

int main()
{
    vector<int> v{5, 1, 1};
    nextPermutation(v);
    vector<int>::iterator it = v.begin();
    while (it != v.end())
    {
        cout << *it << endl;
        it++;
    }
    return 0;
}