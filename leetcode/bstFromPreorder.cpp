#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    TreeNOde *BST(TreeNode *root, int val)
    {
        if (root == NULL)
            return new TreeNode(val);

        if (root->val > val)
        {
            root->left = BST(root->left, val);
            return root;
        }
        else
        {
            root->right = BST(root->right, val);
            return root;
        }
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        if (preorder.size() == 0)
            return NULL;

        TreeNode *root = new TreeNode(preorder[0]);
        for (int i = 1; i < preorder.size(); i++)
        {
            int val = preorder[i];
            root = BST(root, val);
        }
        return root;
    }
};