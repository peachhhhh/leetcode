#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//深度优先遍历
bool dfs(vector<vector<char>> &board, int i, int j, string word, int index)
{
    if(index == word.size()){
        return true;
    }
    bool b = false;
    int nexti, nextj;
    for (int k = 0; k < 4; k++)
    {
        if (k == 0)
        {
            nexti = i - 1;
            nextj = j;
        }
        else if (k == 1)
        {
            nexti = i;
            nextj = j - 1;
        }
        else if (k == 2)
        {
            nexti = i + 1;
            nextj = j;
        }
        else if (k == 3)
        {
            nexti = i;
            nextj = j + 1;
        }
        if (nexti >= 0 && nexti < board.size() && nextj >= 0 && nextj < board[0].size())
        {
            if (board[nexti][nextj] == word[index])//对符合要求的点进一步遍历其周围点，同时暂时改变前一个点，防止重复利用该点
            {
                board[i][j] += 100;
                b = dfs(board, nexti, nextj, word, index + 1);
                board[i][j] -= 100;
                if (b == true)
                {
                    return b;
                }
            }
        }
    }
    return b;
}

bool exist(vector<vector<char>> &board, string word)
{
    bool b = false;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (word[0] == board[i][j])//在二维数组中寻找起点
            {
                b = dfs(board, i, j, word, 1);//找到起点后，开始深度优先遍历上下左右的点
                if (b == true)
                {
                    return b;
                }
            }
        }
    }
    return b;
}

void test()
{
    vector<vector<char>> board =
        {
            {'C', 'A', 'A'},
            {'A', 'A', 'A'},
            {'B', 'C', 'D'}};
    string word = "AAB";
    cout << exist(board, word) << endl;
}

int main()
{
    test();
    return 0;
}