#include <iostream>
#include <vector>
using namespace std;

//状态机
int maxProfit(vector<int> &prices)
{
    if (prices.empty())
    {
        return 0;
    }
    int s1 = -prices[0], s2 = -1000000; //初始化
    for (int i = 1; i < prices.size(); ++i)
    {
        s1 = max(s1, -prices[i]);     //买入价格更低的股
        s2 = max(s2, s1 + prices[i]); //卖出当前股，或者不操作
    }
    return max(0, s2);
}

//巧计，易于理解，实质为状态机
int maxProfit2(vector<int> &prices)
{
    int minvalue = 10000, ans = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        minvalue = min(minvalue, prices[i]); //minvalue记录遍历到现在为止，股价最小的一天
        ans = max(ans, prices[i] - minvalue);
    }
    return ans;
}

void test()
{
    vector<int> v{7, 1, 5, 0, 8, 3, 6, 4};
    cout << maxProfit2(v) << endl;
}

int main()
{
    test();
    return 0;
}