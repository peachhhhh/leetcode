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

//递归，其中函数dfs返回的是当前节点的最大深度，而res表示当前节点为根节点时的二叉树直径（可能不包括当前点）
int dfs(TreeNode *root, int &res)
{
    if (!root)
    {
        return 0;
    }
    int l = dfs(root->left, res), r = dfs(root->right, res);
    res = max(l + r + 1, res);
    return max(l, r) + 1;
}

int diameterOfBinaryTree(TreeNode *root)
{
    int res = 0;
    dfs(root, res);
    return max(0, res - 1);
}

void test()
{
}

int main()
{
    test();
    return 0;
}