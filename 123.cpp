#include <iostream>
#include <vector>
using namespace std;

//状态机
int maxProfit(vector<int> &prices)
{
    int s1 = -1000000, s2 = -1000000, s3 = -1000000, s4 = -1000000; //初始化
    for (int i = 0; i < prices.size(); ++i)
    {
        s1 = max(s1, -prices[i]);     //买入价格更低的股
        s2 = max(s2, s1 + prices[i]); //卖出当前股，或者不操作
        s3 = max(s3, s2 - prices[i]); //第二次买入价格更低的股
        s4 = max(s4, s3 + prices[i]); //第二次卖出当前股，或者不操作
    }
    return max(0, s4);
}

void test()
{
    vector<int> v{7, 1, 5, 0, 8, 3, 6, 4};
    cout << maxProfit(v) << endl;
}

int main()
{
    test();
    return 0;
}