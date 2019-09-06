#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//将所有区间根据左边界从小到大排序，然后从左到右遍历，同时将符合条件的区间合并
static bool compare(const vector<int> &a, const vector<int> &b)
{
    return a[0] < b[0];
}

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.empty())
    {
        return {};
    }
    vector<vector<int>> vv;
    sort(intervals.begin(), intervals.end(), compare);
    vv.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] > vv.back()[1])
        {
            vv.push_back(intervals[i]);
        }
        else if (intervals[i][1] > vv.back()[1])
        {
            vv.back() = {vv.back()[0], intervals[i][1]};
        }
    }
    return vv;
}

int main()
{
    vector<vector<int>> v{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> vv;
    vv = merge(v);
    return 0;
}