#include <iostream>
#include <vector>
#include <algorithm>
//#include <unordered_map>
using namespace std;

//双指针，滑动窗口，hard
string minWindow(string s, string t)
{
    int map[200] = {0};
    for (auto c : t)
    {
        map[c]++;
    }
    int i = 0, j = 0;
    string subs;
    int minlength = s.size(), count = 0; //count用于计数s当前窗口内和t一一对应的相同字符的个数
    while (j < s.size())
    {
        map[s[j]]--;
        if (map[s[j]] >= 0)
        {
            count++;
        }
        while (count == t.size())
        {
            if (j - i + 1 <= minlength)
            {
                minlength = j - i + 1;
                subs = s.substr(i, j - i + 1);
            }
            map[s[i]]++;
            if (map[s[i]] > 0)
            {
                count--;
            }
            i++;
        }
        j++;
    }
    return subs;
}

void test()
{
    string s = "a", t = "a";
    cout << minWindow(s, t) << endl;
}

int main()
{
    test();
    return 0;
}