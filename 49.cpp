#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

//利用哈希表存储排序后相同的字符串
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> hashmap;
    for(auto s : strs){
        string temp = s;
        sort(temp.begin(), temp.end());
        hashmap[temp].push_back(s);
    }
    vector<vector<string>> ans;
    for(auto h : hashmap){
        ans.push_back(h.second); 
    }
    return ans;
}
int main()
{
    
    return 0;
}