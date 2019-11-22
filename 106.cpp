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

//迭代，栈，参考105题
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    if (inorder.empty())
    {
        return NULL;
    }
    stack<TreeNode *> s;
    TreeNode *root = new TreeNode(postorder[postorder.size() - 1]);
    s.push(root);
    for (int i = postorder.size() - 2, j = inorder.size() - 1; i >= 0; --i)
    {
        TreeNode *cur = new TreeNode(postorder[i]), *tmp = NULL;
        while (!s.empty() && s.top()->val == inorder[j])
        {
            tmp = s.top();
            s.pop();
            j--;
        }
        if (tmp)
        {
            tmp->left = cur;
        }
        else
        {
            s.top()->right = cur;
        }
        s.push(cur);
    }
    return root;
}

void test()
{
    vector<int> v1{1, 2, 4, 5, 3, 6, 7};
    vector<int> v2{4, 2, 5, 1, 6, 3, 7};
    cout << buildTree(v1, v2)->val << endl;
}

int main()
{
    test();
    return 0;
}