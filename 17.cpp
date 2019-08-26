#include <iostream>
#include <vector>
using namespace std;

vector<string> letterCombinations(string digits)
{
    vector<string> ans{""};
    int len;
    vector<string> temp{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    if(digits == ""){
        return {};
    }
    for (int i = 0; i < digits.size(); i++)
    {
        len = ans.size();
        for (int j = 0; j < len; j++)
        {
            for (char c : temp[digits[i] - '2'])
            {
                ans.push_back(ans[j] + c);//插入新的
            }
        }
        ans.erase(ans.begin(), ans.begin() + len);//擦除前面旧的
    }

    return ans;
}

int main()
{
    string s = "23";
    vector<string> vs = letterCombinations(s);
    vector<string>::iterator it = vs.begin();
    while(it != vs.end()){
        cout << *it << endl;
        it++;
    }
    return 0;
}