#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//递归
int recursion(TreeNode *t, int &ans)
{
    if (!t)
    {
        return 0;
    }
    int left, right;
    left = max(recursion(t->left, ans), 0); //左子树的最大路径和（包含t的左节点）
    right = max(recursion(t->right, ans), 0); //右子树的最大路径和（包含t的右节点）
    ans = max(left + right + t->val, ans); //更新最大路径和
    return t->val + max(max(left, right), 0); //返回当前节点的左右子树中的包含当前节点的最大路径和
}

int maxPathSum(TreeNode *root)
{
    int ans = -1000000;
    recursion(root, ans);
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