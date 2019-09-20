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

vector<vector<int>> ans{};

//递归，depth记录当前深度，并作为ans的索引
void recursion(TreeNode *t, int depth)
{
    if (t == NULL)
    {
        return;
    }
    if (depth >= ans.size())
    {
        ans.push_back({});
    }
    ans[depth].push_back(t->val);
    recursion(t->left, depth + 1);
    recursion(t->right, depth + 1);
    return;
}

vector<vector<int>> levelOrder(TreeNode *root)
{
    recursion(root, 0);
    return ans;
}

//迭代，队列，每一个完整的for里，向队列中推入下一个depth的所有非NULL节点，同时推出当前depth的所有节点
vector<vector<int>> levelOrder2(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }
    vector<vector<int>> ansans;
    queue<TreeNode *> q;
    q.push(root);
    int depth = 0;
    while (!q.empty())
    {
        ansans.push_back({});
        int qsize = q.size();
        for (int i = 0; i < qsize; i++)
        {
            ansans[depth].push_back(q.front()->val);
            if (q.front()->left)
            {
                q.push(q.front()->left);
            }
            if (q.front()->right)
            {
                q.push(q.front()->right);
            }
            q.pop();
        }
        depth++;
    }
    return ansans;
}

void test()
{
}

int main()
{
    test();
    return 0;
}