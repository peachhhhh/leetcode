#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class MinStack
{
private:
    stack<pair<int, int>> ss;

public:
    MinStack()
    {
    }

    void push(int x)
    {
        if (!ss.empty())
        {
            int down = ss.top().second;
            x > down ? ss.push(make_pair(x, down)) : ss.push(make_pair(x, x));
        }
        else
        {
            ss.push(make_pair(x, x));
        }
    }

    void pop()
    {
        ss.pop();
    }

    int top()
    {
        return ss.top().first;
    }

    int getMin()
    {
        return ss.top().second;
    }
};

void test()
{
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    minStack->getMin(); //-- > 返回 - 3.
    minStack->pop();
    minStack->top();    //-- > 返回 0.
    minStack->getMin(); //-- > 返回 - 2.
    delete minStack;
}

int main()
{
    test();
    return 0;
}