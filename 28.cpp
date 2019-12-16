#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//字符串的模式匹配：BF暴力算法
int strStr1(string ss, string s)
{
    int m = ss.size(), n = s.size();
    if (n == 0)
    {
        return 0;
    }
    int i = 0;
    while (i < m - n + 1) // 留意终止条件
    {
        int j = 0;
        while (j < n && s[j] == ss[i + j])
        {
            j++;
        }
        if (j == n)
        {
            return i;
        }
        i++;
    }
    return -1;
}

//字符串的模式匹配：BM(Boyer-Moore)算法
// https://www.cnblogs.com/gaochundong/p/boyer_moore_string_matching_algorithm.html
void getBadChar(string &s, vector<int> &badchar)
{
    int n = s.size();
    for (int i = 0; i < 256; i++)
    {
        badchar[i] = n; // 默认移动距离为字符串s的长度n
    }
    for (int i = 0; i < n - 1; i++)
    {
        badchar[s[i]] = n - 1 - i; // 对于坏字符s[i]，移动的距离n - 1 - i，相同字符采用最右侧的那个。
    }
}

void getLongestSuffix(string &s, vector<int> &suff)
{
    int n = s.size();
    for (int i = n - 2; i >= 0; i--)
    {
        int j = 0;
        while (i - j >= 0 && s[n - 1 - j] == s[i - j])
        {
            j++;
        }
        suff[i] = j; // suff[i]表示字符串s中，从 i 位置开始往左 与 后缀的最长匹配
    }
}

void getGoodSuffix(string &s, vector<int> &goodsuffix)
{
    int n = s.size();
    vector<int> suff(n - 1, 0);
    getLongestSuffix(s, suff);
    for (int i = 0; i < n; i++)
    {
        goodsuffix[i] = n; // 默认移动距离为字符串s的长度n
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (suff[i] == i + 1) // 若有真前缀与真后缀匹配，则取到最大匹配
        {
            for (int j = 0; j < n - 1; j++)
            {
                goodsuffix[j] = n - 1 - i; // 将所有移动距离更新为 真前缀的尾索引 到 字符串s的尾索引，即 n - 1 - i 
            }
            break;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        goodsuffix[n - 1 - suff[i]] = n - 1 - i;
        // 考虑好后缀，更新移动距离，如果好后缀长度为suff[i]，则字符串s中 n - 1 - suff[i] 位置是坏字符的时候的移动距离为从 i 移动到 n - 1，即 n - 1 - i
        // 然后从左向右更新，从而使得 移动距离 = 好后缀在模式中的当前位置 - 好后缀在模式中最右出现的位置（除去好后缀本身）
    }
}

//此处与BF暴力算法只有5行不同
int strStr2(string ss, string s)
{
    int m = ss.size(), n = s.size();
    if (n == 0)
    {
        return 0;
    }

    vector<int> badchar(256); // 1
    getBadChar(s, badchar);   // 2
    vector<int> goodsuffix(n); // 3
    getGoodSuffix(s, goodsuffix); // 4

    int i = 0;
    while (i < m - n + 1) // 留意终止条件
    {
        int j = n - 1;
        while (j >= 0 && s[j] == ss[i + j])
        {
            j--;
        }
        if (j == -1)
        {
            return i;
        }
        i = i + max(badchar[ss[i + j]] - (n - 1 - j), goodsuffix[j]); // 5
    }
    return -1;
}

//字符串的模式匹配：KMP算法
// https://segmentfault.com/a/1190000008575379
void getNext(string &s, vector<int> &next)
{
    int n = s.size();
    next[0] = -1;
    int i = 0;
    int j = -1;
    while (i < n - 1)
    {
        if (j == -1 || s[i] == s[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

//此处与BF暴力算法只有3行不同
int strStr3(string ss, string s)
{
    int m = ss.size(), n = s.size();
    if (n == 0)
    {
        return 0;
    }

    vector<int> next(n + 1, 0); // 1
    getNext(s, next);           // 2

    int i = 0;
    while (i < m - n + 1) // 留意终止条件
    {
        int j = 0;
        while (j < n && s[j] == ss[i + j])
        {
            j++;
        }
        if (j == n)
        {
            return i;
        }
        i = i + (j - next[j]); // 3
    }
    return -1;
}

void test()
{
    // cout << strStr2("BBC ABCDAB ABCDABCDABDE", "ABCDABC") << endl;
    // cout << strStr2("babbbbbabb", "bbab") << endl;
    cout << strStr2("ababcaababcaabc", "ababcaabc") << endl;
}

int main()
{
    test();
    return 0;
}
