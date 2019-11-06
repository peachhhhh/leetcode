#include <iostream>
#include <vector>
#include <algorithm>
//#include <unordered_map>
using namespace std;

//滑动窗口，类似76题，最小覆盖子串
vector<int> findAnagrams(string s, string p)
{
    int map[200] = {0};
    for (auto &c : p)
    {
        map[c]++;
    }
    int i = 0, j = 0;
    vector<int> res;
    int count = 0; //count用于计数s的当前窗口内和p相同字符的个数
    while (j < s.size())
    {
        if (map[s[j]] > 0) //滑动完右指针，更新map数组
        {
            count++;
        }
        map[s[j]]--;
        while (count == p.size()) //如果相同字符数和字符串p长度相等，则开始移动窗口左端
        {
            if (j - i + 1 == p.size()) //如果滑动窗口和字符串p长度也相等，则找到答案
            {
                res.push_back(i);
            }
            map[s[i]]++;
            if (map[s[i]] > 0)
            {
                count--;
            }
            i++; //左指针往右滑动，同时更新map数组
        }
        j++; //右指针往右滑动
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