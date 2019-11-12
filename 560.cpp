#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//哈希表，hashmap存储<出现过的和，对应个数>，cursum表示从头一直加到当前点的和
int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> hashmap;
    hashmap[0] = 1;
    int cursum = 0, res = 0;
    for (int &n : nums)
    {
        cursum += n;
        if (hashmap[cursum - k] != 0)
        {
            res += hashmap[cursum - k];
        }
        hashmap[cursum]++;
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