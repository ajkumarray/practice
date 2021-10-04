#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int> > result;

    void permutation(vector<int> &nums, int i)
    {
        if (i == nums.size())
        {
            result.push_back(nums);
            return;
        }

        for (int j = i; j < nums.size(); j++)
        {
            swap(nums[i], nums[j]);
            permutation(nums, i + 1);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int> > permute(vector<int> &nums)
    {
        permutation(nums, 0);
        return result;
    }
};