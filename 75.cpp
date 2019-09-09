#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//三指针，一个从左开始记录0的最右端的索引，一个从右开始记录2的最左端的索引，一个作为当前点索引向右移动，直到相撞
void sortColors(vector<int> &nums)
{
    int n = nums.size();
    int left = 0, right = n - 1;
    int curr = 0;
    while (left <= right && curr <= right)
    {
        if(nums[curr] < 1){
            swap(nums[left],nums[curr]);
            left++;
            curr++;
        }
        else if(nums[curr] > 1){
            swap(nums[right],nums[curr]);
            right--;
        }
        else{
            curr++;
        }
    }
}
void test()
{
    vector<int> v{1, 2, 1, 1, 0, 0, 2, 1, 0, 0, 2};
    sortColors(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    test();
    return 0;
}