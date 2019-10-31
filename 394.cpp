#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

//栈，双栈，一个存数字，一个存当前字符串，遇到'['进栈，遇到']'则更新栈顶并记录栈顶然后出栈
string decodeString(string s)
{
    stack<string> ss;
    stack<int> si;
    string cur = "";
    int n = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            n = n * 10 + s[i] - '0';
        }
        else if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
        {
            cur = cur + s[i];
        }
        else if (s[i] == '[')
        {
            ss.push(cur);
            si.push(n);
            cur = "";
            n = 0;
        }
        else
        {
            int tmp = si.top();
            si.pop();
            for (int j = 0; j < tmp; j++)
            {
                ss.top() += cur;
            }
            cur = ss.top();
            ss.pop();
        }
    }
    return cur;
}

void test()
{
    string s = "s2[ab]t3[cd4[ef]u]g";
    cout << decodeString(s) << endl;
}

int main()
{
    test();
    return 0;
}