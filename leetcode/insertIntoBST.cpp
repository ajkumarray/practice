#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == NULL)
            return new TreeNode(val);

        if (root->val > val)
        {
            root->left = insertIntoBST(root->left, val);
            return root;
        }
        else
        {
            root->right = insertIntoBST(root->right, val);
            return root;
        }
    }
};