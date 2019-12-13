#include <iostream>
#include <vector>
#include <algorithm>
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
    while (i < m)
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
int strStr2(string ss, string s)
{
}

//字符串的模式匹配：KMP算法
//getnext() -> https://www.jianshu.com/p/bc39539c1db4
void getnext(string s, vector<int> &next)
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
    
    vector<int> next(n + 1, 0); //1
    getnext(s, next);           //2

    int i = 0;
    while (i < m)
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
        i = i + (j - next[j]); //3
    }
    return -1;
}

void test()
{
    strStr3("BBC ABCDAB ABCDABCDABDE", "ABCDABD");
}

int main()
{
    test();
    return 0;
}
