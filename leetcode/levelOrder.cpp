#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int> > levelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int> > ans;
        if (root == NULL)
            return ans;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                TreeNode *nde = q.front();
                q.pop();
                level.push_back(nde->val);
                if (nde->left)
                    q.push(nde->left);
                if (nde->right)
                    q.push(nde->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};