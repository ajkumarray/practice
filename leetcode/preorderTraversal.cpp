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
            ray.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        printBST(root);
        return ray;
    }
};