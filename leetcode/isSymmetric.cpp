#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isMirror(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
            return true;

        if (!root1 || !root2)
            return false;

        if (root1->val != root2->val)
            return false;

        return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return NULL;

        TreeNode *root1 = root->left;
        TreeNode *root2 = root->right;

        return isMirror(root1, root2);
    }
};