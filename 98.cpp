#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//递归，当前节点的值是左子树的最大值，是右子树的最小值。
bool recursion(TreeNode *t, long min, long max)
{
    if (t == NULL)
    {
        return true;
    }
    if (!recursion(t->left, min, t->val))
    {
        return false;
    }
    if (!recursion(t->right, t->val, max))
    {
        return false;
    }
    if (t->val <= min || t->val >= max)
    {
        return false;
    }
    return true;
}

bool isValidBST(TreeNode *root)
{
    return recursion(root, -2147483649, 2147483648);
}

void test()
{
}

int main()
{
    test();
    return 0;
}