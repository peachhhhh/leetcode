#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> ans;

//递归
vector<int> inorderTraversal(TreeNode *root)
{
    if (root != nullptr)
    {
        inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right);
    }
    return ans;
}

//迭代，利用栈
vector<int> inorderTraversal2(TreeNode *root)
{
    vector<int> anss;
    stack<TreeNode> ss;
    TreeNode *t = root;
    while (t != nullptr || !ss.empty())
    {
        while (t != nullptr)
        {
            ss.push(*t);
            t = t->left;
        }
        if (!ss.empty())
        {
            anss.push_back(ss.top().val);
            t = ss.top().right;
            ss.pop();
        }
    }
    return anss;
}

void test()
{
}

int main()
{
    test();
    return 0;
}