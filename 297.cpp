#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//递归实现
class Codec
{
public:
    string serialize(TreeNode *root) //前序遍历
    {
        if (!root)
            return "NULL";
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }

    TreeNode *deserialize(string data)
    {
        istringstream in(data);
        return helper(in);
    }

    TreeNode *helper(istringstream &in)
    {
        string val;
        in >> val;
        if (val == "NULL")
            return nullptr;
        auto root = new TreeNode(stoi(val));
        root->left = helper(in);
        root->right = helper(in);
        return root;
    }
};

void test()
{
}

int main()
{
    test();
    return 0;
}