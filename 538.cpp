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

//深度优先遍历
void dfs(TreeNode *root, int &sum)
{
    if (!root)
    {
        return;
    }
    dfs(root->right, sum);
    root->val += sum;
    sum = root->val;
    dfs(root->left, sum);
}

TreeNode *convertBST(TreeNode *root)
{
    int sum = 0;
    dfs(root, sum);
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