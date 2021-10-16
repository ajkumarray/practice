#include <bits/stdc++.h>

using namespace std;

class Solution //   search in rotated sorted array
{
public:
    int findMin(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        int ans = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= nums[0])
                left = mid + 1;
            else
            {
                ans = nums[mid];
                right = mid - 1;
            }
        }
        if (ans == -1)
            return nums[0];

        return ans;
    }
};