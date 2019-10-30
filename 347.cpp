#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <unordered_map>
using namespace std;

//哈希表
vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> hashmap;
    for (auto n : nums)
    {
        hashmap[n]++;
    }
    vector<list<int>> v(nums.size() + 1);
    for (auto h : hashmap)
    {
        v[h.second].push_back(h.first);
    }
    vector<int> res;
    int kk = 0;
    for (int i = nums.size(); i >= 0; i--)
    {
        while (!v[i].empty())
        {
            res.push_back(v[i].front());
            v[i].pop_front();
            kk++;
        }
        if (kk == k)
        {
            return res;
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