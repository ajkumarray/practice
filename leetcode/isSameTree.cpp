#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        else if (!p || !q)
            return false;

        bool ans = (p->val == q->val);
        ans = ans && (isSameTree(p->left, q->left));
        ans = ans && (isSameTree(p->right, q->right));
        return ans;
    }
};