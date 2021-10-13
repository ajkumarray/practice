#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void sort(TreeNode *root, vector<int> &ray)
    {
        if (!root)
            return;

        sort(root->left, ray);
        ray.push_back(root->val);
        sort(root->right, ray);
    }

    bool findTarget(TreeNode *root, int k)
    {
        vector<int> ray;
        sort(root, ray);

        int left = 0, right = ray.size() - 1;
        while (left < right)
        {
            if (ray[left] + ray[right] == k)
                return true;
            else if (ray[left] + ray[right] > k)
                right--;
            else
                left++;
        }
        return false;
    }
};