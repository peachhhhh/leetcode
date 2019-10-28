#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//树型动态规划，pre == 1 表示父节点被选中
unordered_map<TreeNode *, int> dp;

int dfs(TreeNode *root, int pre)
{
    if (!root)
    {
        return 0;
    }
    if (dp[root] && pre == 0)
    {
        return dp[root];
    }
    if (pre == 1)
    {
        return dfs(root->left, 0) + dfs(root->right, 0);
    }
    dp[root] = max(dfs(root->left, 0) + dfs(root->right, 0), root->val + dfs(root->left, 1) + dfs(root->right, 1));
    return dp[root];
}

int rob(TreeNode *root)
{
    return dfs(root, 0);
}

//简化版，不用数组
//dfs2中，l是root的左子树的两个孩子节点的答案和，r是root的右子树的两个孩子节点的答案和
//而lr是root的左子树和右子树的答案和
int dfs2(TreeNode *root, int &lr)
{
    if(!root)
    {
        return 0;
    }
    int l = 0, r = 0;
    lr = dfs2(root->left, l) + dfs2(root->right, r);
    return max(l + r + root->val, lr);
}

int rob2(TreeNode *root)
{
    int lr = 0;
    return dfs2(root, lr);
}

void test()
{
}

int main()
{
    test();
    return 0;
}