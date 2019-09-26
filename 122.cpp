#include <iostream>
#include <vector>
using namespace std;

//贪心，只要股价一上涨就卖出，获得收益
int maxProfit(vector<int> &prices)
{
    if (prices.empty())
    {
        return 0;
    }
    int ans = 0;
    for (int i = 1; i < prices.size(); ++i)
    {
        if(prices[i] > prices[i - 1]){
            ans += prices[i] - prices[i - 1];
        }
    }
    return ans;
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