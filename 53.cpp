#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int> &nums)
{
    int maxsum = nums[0];
    int cursum = 0;
    for(auto i : nums){
        cursum = max(i, cursum + i);
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
