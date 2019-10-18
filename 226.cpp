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

//递归（或迭代用队列）
void recursion(TreeNode *t)
{
    if (!t)
    {
        return;
    }
    TreeNode *tmp;
    tmp = t->right;
    t->right = t->left;
    t->left = tmp;
    recursion(t->left);
    recursion(t->right);
}

TreeNode *invertTree(TreeNode *root)
{
    recursion(root);
    return root;
}

void test()
{
}

int main()
{
    test();
    return 0;
}