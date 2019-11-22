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

//递归，dfs，参考105题
TreeNode *dfs(vector<int> &inorder, vector<int> &postorder, int il, int ir, int pl, int pr, unordered_map<int, int> &m)
{
    if (il > ir || pl > pr)
    {
        return NULL;
    }
    TreeNode *node = new TreeNode(postorder[pr]);
    int len = ir - m[postorder[pr]];
    node->left = dfs(inorder, postorder, il, ir - len - 1, pl, pr - len - 1, m);
    node->right = dfs(inorder, postorder, ir - len + 1, ir, pr - len, pr - 1, m);
    return node;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    unordered_map<int, int> hashmap;
    for (int i = 0; i < inorder.size(); i++)
    {
        hashmap[inorder[i]] = i;
    }
    return dfs(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, hashmap);
}

//迭代，栈，参考105题，时间差不多，空间更节约
TreeNode *buildTree2(vector<int> &inorder, vector<int> &postorder)
{
    if (inorder.empty())
    {
        return NULL;
    }
    stack<TreeNode *> s;
    TreeNode *root = new TreeNode(postorder.back());
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