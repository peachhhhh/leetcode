#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//基于84题的单调栈，逐行遍历，dp记录该行每个为‘1’的点向上的高度，利用单调栈计算该行的最大矩形
int maximalRectangle(vector<vector<char>> &matrix)
{
    if (matrix.empty())
    {
        return 0;
    }
    int m = matrix.size(), n = matrix[0].size();
    vector<int> dp(n, 0);
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == '0')
            {
                dp[j] = 0;
            }
            else
            {
                dp[j] += 1;
            }
        }
        ans = max(ans, largestRectangleArea(dp));
    }
    return ans;
}

//84题单调栈
int largestRectangleArea(vector<int> &dp)
{
    stack<int> ss;
    dp.push_back(0);
    int maxans = 0, cur = 0;
    for (int i = 0; i < dp.size(); i++)
    {
        while (!ss.empty() && dp[i] < dp[ss.top()])
        {
            int temp = ss.top();
            ss.pop();
            if (ss.empty())
            {
                cur = dp[temp] * i;
            }
            else
            {
                cur = dp[temp] * (i - ss.top() - 1);
            }
            maxans = max(cur, maxans);
        }
        ss.push(i);
    }
    dp.pop_back();
    return maxans;
}

void test()
{
    
}

int main()
{
    test();
    return 0;
}