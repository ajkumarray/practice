#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool check(TreeNode *root, long min, long max)
    {
        if (!root)
            return true;
        if (root->val >= max || root->val <= min)
            return false;

        return check(root->left, min, root->val) && check(root->right, root->val, max);
    }

    bool isValidBST(TreeNode *root)
    {
        return check(root, LONG_MIN, LONG_MAX);
    }
};