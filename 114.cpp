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

//右子树接左子树的最右节点，然后左子树换到右子树，左子树置空。
void flatten(TreeNode *root)
{
    while (root != nullptr)
    {
        if (root->left != nullptr)
        {
            TreeNode *t = root->left;
            while (t->right != nullptr)
            {
                t = t->right;
            }
            t->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        root = root->right;
    }
    return;
}

void test()
{
}

int main()
{
    test();
    return 0;
}
