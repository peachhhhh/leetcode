#include <iostream>
#include <vector>
using namespace std;

//回溯法(递归？or分治？)，规则：从左往右数，“（ ”的数目一定大于等于“ ）”。
vector<string> generateParenthesis(int n)
{
    vector<string> s;
    backtrack(s, "", 0, 0, n);
    return s;
}

void backtrack(vector<string> &v, string s, int left, int right, int n)
{
    if (s.size() == 2 * n)
    {
        v.push_back(s);
        return;
    }
    if (left < n)
    {
        backtrack(v, s + "(", left + 1, right, n);
    }
    if (right < left)
    {
        backtrack(v, s + ")", left, right + 1, n);
    }
}

int main()
{
    return 0;
}