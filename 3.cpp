#include<cstring>
#include<iostream>

using namespace std;

int longestSubstring(string s){
	const int MAX = 256;
	int m[MAX];
	memset(m, -1, sizeof(m));
	int maxlenth = 0;
	int last_reapeat_index = -1;
	for(int i = 0;i < s.size();i++){
		if(m[s[i]] != -1 && m[s[i]] > last_reapeat_index){
			last_reapeat_index = m[s[i]];
		}
		if(i - last_reapeat_index > maxlenth){
			maxlenth = i - last_reapeat_index;
		}
		m[s[i]] = i;
	}
	return maxlenth;
}

