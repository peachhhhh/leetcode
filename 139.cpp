#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//动态规划
bool wordBreak(string s, vector<string> &wordDict)
{
    vector<bool> dp(s.size() + 1, 0);
    dp[0] = 1;
    int len;
    for (int i = 1; i <= s.size(); i++)
    {
        for (auto &j : wordDict)
        {
            len = j.size();
            if (len <= i && s.substr(i - len, len) == j)
            {
                dp[i] = dp[i - len]; //状态转移方程
                if (dp[i] == 1)
                {
                    break;
                }
            }
        }
    }
    return dp[s.size()];
}

void test()
{
}

int main()
{
    test();
    return 0;
}