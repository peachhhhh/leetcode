#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

//栈（存放索引），遍历时，小于栈顶的直接入栈，大于栈顶的，先出栈（出栈时给结果赋值），直到小于栈顶
vector<int> dailyTemperatures(vector<int> &T)
{
    if (T.empty())
    {
        return {};
    }
    vector<int> res(T.size(), 0);
    stack<int> ss;
    for (int i = 0; i < T.size(); ++i)
    {
        while (!ss.empty() && T[ss.top()] < T[i])
        {
            res[ss.top()] = i - ss.top();
            ss.pop();
        }
        ss.push(i);
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
