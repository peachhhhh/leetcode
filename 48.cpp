#include <iostream>
#include <vector>
using namespace std;
void swap4(int &a, int &b, int &c, int &d)
{
    int buff;
    buff = d;
    d = c;
    c = b;
    b = a;
    a = buff;
}
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = i; j < n - i - 1; j++)
        {
            swap4(matrix[i][j], matrix[j][n - i - 1], matrix[n - i - 1][n - j - 1], matrix[n - j - 1][i]);
        }
    }
}
int main()
{
    vector<vector<int>> matrix{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    rotate(matrix);
    return 0;
}