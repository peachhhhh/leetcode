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

//递归，哈希表用于每次查找中序遍历里的根节点的位置，然后类似二分查找的思路递归建立树（留意：dfs函数的参数中，用m的引用，而不是m，减少运行时间和空间）
TreeNode *dfs(vector<int> &pre, int pleft, int pright, vector<int> &in, int ileft, int iright, unordered_map<int, int> &m)
{
    if (pleft > pright || ileft > iright)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(pre[pleft]);
    int len = m[pre[pleft]] - ileft;
    root->left = dfs(pre, pleft + 1, pleft + len, in, ileft, ileft + len - 1, m);
    root->right = dfs(pre, pleft + len + 1, pright, in, ileft + len + 1, iright, m);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int, int> m;
    int s = inorder.size();
    for (int i = 0; i < s; i++)
    {
        m[inorder[i]] = i;
    }
    return dfs(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, m);
}

//迭代，栈，
TreeNode *buildTree2(vector<int> &pre, vector<int> &in)
{
    if (pre.empty())
        return NULL;
    stack<TreeNode *> s;
    TreeNode *root = new TreeNode(pre[0]);
    s.push(root);
    for (int i = 1, j = 0; i < pre.size(); i++)
    {
        TreeNode *back = NULL, *cur = new TreeNode(pre[i]);
        while (!s.empty() && s.top()->val == in[j])
            back = s.top(), s.pop(), j++;
        if (back)
            back->right = cur;
        else
            s.top()->left = cur;
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