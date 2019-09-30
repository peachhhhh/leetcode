#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int ans = 0;
    for(int i : nums){
        ans ^= i;
    }
    return ans;
}

void test()
{
}

int main()
{
    test();
    return 0;
}