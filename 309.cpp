#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//动态规划，时间复杂度o(n)，空间复杂度o(n)
int maxProfit(vector<int> &prices)
{
    if (prices.empty())
    {
        return 0;
    }
    int n = prices.size();
    int sold[n] = {0}, hold[n] = {-prices[0]}, rest[n] = {0};
    for (int i = 1; i < n; i++)
    {
        sold[i] = hold[i - 1] + prices[i];
        hold[i] = max(hold[i - 1], rest[i - 1] - prices[i]);
        rest[i] = max(rest[i - 1], sold[i - 1]);
    }
    return max(rest[n - 1], sold[n - 1]);
}

//修改上述动态规划，减小空间复杂度到o(1)
int maxProfit2(vector<int> &prices)
{
    if (prices.empty())
    {
        return 0;
    }
    int n = prices.size();
    int sold = 0, hold = -prices[0], rest = 0;
    for (int i = 1; i < n; i++)
    {
        int tmp = sold;
        sold = hold + prices[i];
        hold = max(hold, rest - prices[i]);
        rest = max(rest, tmp);
    }
    return max(rest, sold);
}

void test()
{
    vector<int> v{1, 2, 3, 0, 2};
    cout << maxProfit(v) << endl;
}

int main()
{
    test();
    return 0;
}
