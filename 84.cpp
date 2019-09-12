#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//单调栈，该题理解参考https://blog.csdn.net/Zolewit/article/details/88863970
int largestRectangleArea(vector<int> &heights)
{
    stack<int> ss;
    heights.push_back(0);
    int maxarea = 0, cur = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        while (!ss.empty() && heights[i] < heights[ss.top()])
        {
            int temp = ss.top();
            ss.pop(); //先出栈，再计算面积
            if (ss.empty())
            {
                cur = heights[temp] * i;
            }
            else
            {
                cur = heights[temp] * (i - ss.top() - 1);
            }
            maxarea = max(maxarea, cur);
        }
        ss.push(i);
    }
    return maxarea;
}

void test()
{
    vector<int> v{2, 1, 2};
    cout << largestRectangleArea(v) << endl;
}

int main()
{
    test();
    return 0;
}