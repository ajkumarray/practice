#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsDuplicates(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] == nums[i])
            {
                return true;
            }
        }
        return false;
    }
};