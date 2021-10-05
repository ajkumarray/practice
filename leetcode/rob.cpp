#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int fun(int curr, int target, vector<int> &nums, vector<int> &v)
    {
        if (curr > target)
            return 0;

        if (v[curr] != -1)
            return v[curr];

        int l = nums[curr] + fun(curr + 2, target, nums, v);
        int r = nums[curr] + fun(curr + 3, target, nums, v);

        v[curr] = max(l, r);
        return v[curr];
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> v(n, -1);
        return max(fun(0, n - 1, nums, v), fun(1, n - 1, nums, v));
    }
};