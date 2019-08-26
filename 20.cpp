#include <iostream>
#include <stack>
using namespace std;

//栈，先进后出，找到最中间的括号对，左括号出栈，若最后栈空，则true
bool isValid(string s)
{
    if (s == "")
    {
        return true;
    }
    if (s.size() % 2 != 0)
    {
        return false;
    }
    stack<char> ss;
    ss.push('$');
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ')' && ss.top() == '(' || s[i] == ']' && ss.top() == '[' || s[i] == '}' && ss.top() == '{')
        {
            ss.pop();
        }
        else
        {
            ss.push(s[i]);
        }
    }
    return ss.top() == '$' ? true : false;
}

int main()
{
    string s = "()][";
    cout << isValid(s) << endl;
    return 0;
}