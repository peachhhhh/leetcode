#include <iostream>
#include <stack>
using namespace std;

//该题可用动态规划，栈，或者两次遍历，三种方法做
//此方法为栈，栈中记录字符串每个字符的下标，若栈顶与下一个字符构成括号，则计算此时长度，即下标差，遍历
int longestValidParentheses(string s)
{
    int maxnum = 0;
    if (s.size() == 0 || s.size() == 1)
    {
        return 0;
    }
    stack<int> sta;
    sta.push(-1);
    for (int i = 0; i < s.size(); i++)
    {
        if(sta.top() == -1){
            sta.push(i);
            continue;
        }
        if (s[sta.top()] == '(' && s[i] == ')')
        {
            sta.pop();
            maxnum = max(maxnum, i - sta.top());
        }
        else
        {
            sta.push(i);
        }
    }
    return maxnum;
}

int main()
{
    string s = "(()";
    cout << longestValidParentheses(s) << endl;
    return 0;
}