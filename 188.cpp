#include <iostream>
#include <vector>
using namespace std;

//122题的贪心算法
int greedy(vector<int> &prices)
{
    int ans = 0;
    for (int i = 1; i < prices.size(); ++i)
    {
        if (prices[i] > prices[i - 1])
        {
            ans += prices[i] - prices[i - 1];
        }
    }
    return ans;
}

//状态机
int maxProfit(int k, vector<int> &prices)
{
    if (k > prices.size() / 2)
    {
        return greedy(prices);
    }
    vector<int> v(2 * k + 1, -1000000);
    v[0] = 0; //初始状态
    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = 1; j < 2 * k + 1; j += 2)
        {
            v[j] = max(v[j], v[j - 1] - prices[i]);     //第(j+1)/2次买入价格更低的股
            v[j + 1] = max(v[j + 1], v[j] + prices[i]); //第(j+1)/2次卖出当前股，或者不操作
        }
    }
    return max(0, v[2 * k]);
}

void test()
{
    vector<int> prices{1, 2, 3, 4, 5, 6, 7};
    int k = 4;
    k = min(k, (int)prices.size() / 2);
    cout << k << endl;
}

int main()
{
    test();
    return 0;
}