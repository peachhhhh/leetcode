#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//回溯
int paths(TreeNode *root, int sum)
{
    if (root == nullptr)
    {
        return 0;
    }
    int res = 0;
    if (root->val == sum)
    {
        res += 1;
    }
    res += paths(root->left, sum - root->val);
    res += paths(root->right, sum - root->val);
    return res;
}

int pathSum(TreeNode *root, int sum)
{

    if (root == nullptr)
    {
        return 0;
    }
    return paths(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
}

//更快的回溯
void pathSumCore(TreeNode *root, int sum, vector<int> &path, int &res)
{
    if (root == nullptr)
    {
        return;
    }
    path.push_back(root->val);
    int curSum = 0;
    for (int i = path.size() - 1; i >= 0; --i)
    {
        curSum += path[i];
        if (curSum == sum)
        {
            res++;
        }
    }
    pathSumCore(root->left, sum, path, res);
    pathSumCore(root->right, sum, path, res);
    path.pop_back();
}

int pathSum(TreeNode *root, int sum)
{
    vector<int> path;
    int res = 0;
    pathSumCore(root, sum, path, res);
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

static auto x = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();