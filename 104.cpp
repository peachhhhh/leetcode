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

//递归
int maxDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

//迭代，队列，每次推入在同一层的所有节点，迭代树的深度depth，并推出前一层的所有节点
int maxDepth2(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    queue<TreeNode *> q;
    q.push(root);
    int depth = 0;
    while (!q.empty())
    {
        int num = q.size();
        for (int i = 0; i < num; i++)
        {
            TreeNode *temp = q.front();
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
            q.pop();
        }
        depth++;
    }
    return depth;
}

void test()
{
}

int main()
{
    test();
    return 0;
}