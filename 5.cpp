#include <iostream>
using namespace std;

//manache 马拉车方法
string longestPalindrome(string str)
{
    
    if(str == ""){
        return "";
    }
    string s = "$";
    for (int i = 0; i < str.length(); i++)
    {
        s += "#";
        s += str[i];
    }
    s += "#0";
    cout << s << endl;
    //system("pause");
    int maxlength[s.length()] = {0};
    int maxright = 0;
    int flag = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (maxright > i)
        {
            maxlength[i] = min(maxlength[2 * flag - i], maxright - i);
        }
        else
        {
            maxlength[i] = 1;
        }
        if(i - maxlength[i] >= 0 && i + maxlength[i] < s.length()){
            while (s[i - maxlength[i]] == s[i + maxlength[i]])
            {
                maxlength[i]++;
            }
        }
        if (maxlength[i] > maxlength[flag])
        {
            flag = i;
            maxright = i + maxlength[i] - 1;
        }
    }
    //return string(s, 2 * flag - maxright, maxlength[flag] * 2 - 1);
    //cout<<flag<<endl;
    //cout<<maxright<<endl;
    return string(str, (2 * flag - maxright ) / 2, maxlength[flag] - 1);
    //return s;
}

int main()
{
    string a = "bananas";
    cout << longestPalindrome(a) << endl;
    //cout << longestPalindrome(a).length() << endl;
    system("pause");
    return 0;
}