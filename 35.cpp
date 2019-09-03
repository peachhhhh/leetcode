#include <iostream>
#include <vector>
using namespace std;

vector<int> buff;
vector<vector<int>> sum;

//回溯算法
void backtrack(vector<int> &candidates, int left, int cur)
{
    if (cur == 0)
    {
        sum.push_back(buff);
        return;
    }
    if (cur < 0)
    {
        return;
    }
    for (int i = left; i < candidates.size(); i++)
    {
        buff.push_back(candidates[i]);
        backtrack(candidates, i, cur - candidates[i]);
        buff.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    backtrack(candidates, 0, target);
    return sum;
}

int main()
{
    vector<int> v{6, 3, 2, 7};
    int t = 7;
    combinationSum(v, t);
    for (int i = 0; i < sum.size(); i++)
    {
        for (int j = 0; j < sum[i].size(); j++)
        {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}