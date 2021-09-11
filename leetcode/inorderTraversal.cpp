class Solution
{
public:
    vector<int> ray;

    void printBST(TreeNode *root)
    {
        if (root != NULL)
        {
            inorderTraversal(root->left);
            ray.push_back(root->val);
            inorderTraversal(root->right);
        }
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        printBST(root);
        return ray;
    }
};