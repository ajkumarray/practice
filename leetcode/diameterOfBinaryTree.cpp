#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root, int *height)
    {
        int lHeight = 0, rHeight = 0;
        int lDiameter = 0, rDiameter = 0;
        if (root == NULL)
        {
            *height = 0;
            return 0;
        }
        lDiameter = diameterOfBinaryTree(root->left, &lHeight);
        rDiameter = diameterOfBinaryTree(root->right, &rHeight);
        *height = max(lHeight, rHeight) + 1;
        return max(lHeight + rHeight + 1, max(lDiameter, rDiameter));
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int height = 0;
        return (diameterOfBinaryTree(root, &height) - 1);
    }
};