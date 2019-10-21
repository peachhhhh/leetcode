#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

//动态规划，将数组每k个划分一组，窗口滑动时，其最大值等于在左侧组内最大值和右侧组内最大值的比较，故先按从左到右和从右到左分别求组内的最大值的上升序列。
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    if (nums.empty())
    {
        return {};
    }
    int n = nums.size();
    vector<int> l(n), r(n), ans(n - k + 1);
    for (int i = 0; i < n; i++)
    {
        if (i % k == 0)
        {
            l[i] = nums[i];
        }
        else
        {
            l[i] = max(nums[i], l[i - 1]);
        }
        if ((n - 1 - i) % k == k - 1 || i == 0)
        {
            r[n - 1 - i] = nums[n - 1 - i];
        }
        else
        {
            r[n - 1 - i] = max(nums[n - 1 - i], r[n - i]);
        }
    }
    for (int i = 0; i <= n - k; i++)
    {
        ans[i] = max(r[i], l[i + k - 1]);
    }
    return ans;
}

//双向队列deque，重点：队列中只保存当前窗口中比即将遍历到的nums[i]要大的值
vector<int> maxSlidingWindow2(vector<int> &nums, int k)
{
    vector<int> res;
    deque<int> q;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (!q.empty() && q.front() == i - k)
        {
            q.pop_front();
        }
        while (!q.empty() && nums[q.back()] < nums[i])
        {
            q.pop_back();
        }
        q.push_back(i);
        if (i >= k - 1)
        {
            res.push_back(nums[q.front()]);
        }
    }
    return res;
}

void test()
{
}

int main()
{
    test();
    return 0;
}