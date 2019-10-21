#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//贪心，从左下角出发
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    if (matrix.empty() || matrix[0].empty())
    {
        return false;
    }
    int m = matrix.size(), n = matrix[0].size();
    int i = m - 1, j = 0;
    while (i >= 0 && j < n)
    {
        if (matrix[i][j] > target)
        {
            i--;
        }
        else if (matrix[i][j] < target)
        {
            j++;
        }
        else
        {
            return true;
        }
    }
    return false;
}

void test()
{
}

int main()
{
    test();
    return 0;
}