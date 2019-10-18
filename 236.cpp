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

//递归，p的祖先节点返回p，q的祖先节点返回q，如果它同时是俩节点的祖先，那么返回自身，否则返回nullptr
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root || root == p || root == q)
    {
        return root;
    }
    TreeNode *l, *r;
    l = lowestCommonAncestor(root->left, p, q);
    r = lowestCommonAncestor(root->right, p, q);
    if (!l)
    {
        return r;
    }
    if (!r)
    {
        return l;
    }
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