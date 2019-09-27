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
int ans = -1000000;

int recursion(TreeNode *t)
{
    if (!t)
    {
        return 0;
    }
    int left, right;
    left = max(recursion(t->left), 0);
    right = max(recursion(t->right), 0);
    ans = max(left + right + t->val, ans);
    return t->val + max(max(left, right), 0);
}

int maxPathSum(TreeNode *root)
{
    recursion(root);
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
