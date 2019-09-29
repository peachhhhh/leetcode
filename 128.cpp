#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

//哈希表
int longestConsecutive(vector<int> &nums)
{
    unordered_map<int, int> hashmap;
    int ans = 0, cur = 1;
    for (int num : nums)
    {
        hashmap[num] = 1;
    }
    for (int num : nums)
    {
        if (!hashmap[num - 1]) //若当前数num是开头，则在哈希表中往后遍历（num++），计算能到达的最长序列长度
        {
            while (hashmap[num + 1])
            {
                num++;
                cur++;
            }
            ans = max(ans, cur);
            cur = 1;
        }
    }
    return ans;
}

void test()
{
    vector<int> nums{30, 2, 3, 4, 5, 60};
    cout << longestConsecutive(nums) << endl;
}

int main()
{
    test();
    return 0;
}