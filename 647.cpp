#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//中心扩展法，类似题，第5题，最长回文子串
int extend(string &s, int i, int j)
{
    int ans = 0;
    while (i >= 0 && j < s.size() && s[i] == s[j])
    {
        i--;
        j++;
        ans++;
    }
    return ans;
}

int countSubstrings(string &s)
{
    int res = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        res += extend(s, i, i);
        res += extend(s, i, i + 1);
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
