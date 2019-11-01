#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//贪心算法，先按身高从大到小排序，再从高到矮，按顺序插入，因此每次插入时，大于等于当前身高的身高都已经插入，故直接找到其位置，即p.back()
static bool help(vector<int> &a, vector<int> &b)
{
    return (a.front() != b.front()) ? a.front() > b.front() : a.back() < b.back();
}

vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
{
    sort(people.begin(), people.end(), help);
    vector<vector<int>> res;
    for (auto &p : people)
    {
        res.insert(res.begin() + p.back(), move(p));
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