#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> removeDuplicates(vector<int> &nums)
    {
        vector<int> result;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] == nums[i])
            {
                result.push_back(nums[i]);
            }
        }
        return result;
    }
};