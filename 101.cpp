#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//递归，左右子树互为左右镜像
bool recursion(TreeNode *t, TreeNode *tt)
{
    if (t == NULL && tt == NULL)
    {
        return true;
    }
    if (t == NULL || tt == NULL)
    {
        return false;
    }
    if (!recursion(t->left, tt->right))
    {
        return false;
    }
    if (!recursion(t->right, tt->left))
    {
        return false;
    }
    if (t->val != tt->val)
    {
        return false;
    }
    return true;
}

bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }
    return recursion(root->left, root->right);
}

//迭代，队列，要比较的两个节点同时进队列，出队列时若不等，则false
bool isSymmetric2(TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }
    queue<TreeNode *> q;
    q.push(root->left);
    q.push(root->right);
    while (!q.empty())
    {
        TreeNode *t = q.front();
        q.pop();
        TreeNode *tt = q.front();
        q.pop();
        if (t == NULL && tt == NULL)
        {
            continue;
        }
        if (t == NULL || tt == NULL)
        {
            return false;
        }
        if (t->val != tt->val)
        {
            return false;
        }
        q.push(t->left);
        q.push(tt->right);
        q.push(t->right);
        q.push(tt->left);
    }
    return true;
}

void test()
{
}

int main()
{
    test();
    return 0;
}