#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int> &nums)
{
    int maxsum = nums[0];
    int cursum = 0;
    for(auto i : nums){
        if(cursum > 0){
            cursum += i;
        }
        else{
            cursum = i;//若当前和小于0，从i位置重新开始计算和
        }
        maxsum = max(cursum, maxsum);
    }
    return maxsum;
}

int main()
{
    vector<int> v{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(v) << endl;
    return 0;
}
