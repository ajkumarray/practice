#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int left, int right)
    {
        int mid = left + (right - left) / 2;
        if ((mid == 0 || nums[mid - 1] <= nums[mid]) && (mid == nums.size() - 1 || nums[mid] >= nums[mid + 1]))
            return mid;
        else if (mid > 0 && nums[mid - 1] > nums[mid])
            return search(nums, left, mid - 1);
        else
            return search(nums, mid + 1, right);
    }

    int findPeakElement(vector<int> &nums)
    {
        return search(nums, 0, nums.size() - 1);
    }
};