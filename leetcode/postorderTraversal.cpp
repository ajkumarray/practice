#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> ray;

    void printBST(TreeNode *root)
    {
        if (root != NULL)
        {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            ray.push_back(root->val);
        }
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        printBST(root);
        return ray;
    }
};