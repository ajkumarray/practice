class Solution
{
public:
    vector<int> binarySearch(vector<int> &nums, int l, int r, int target)
    {
        if (l > r)
        {
            vector<int> ray{INT_MAX, -1};
            return ray;
        }

        int mid = l + (r - l) / 2;

        if (target == nums[mid])
        {
            vector<int> left = binarySearch(nums, l, mid - 1, target);
            vector<int> right = binarySearch(nums, mid + 1, r, target);

            vector<int> ray { min(mid, left[0]), max(mid, right[1]) }
            return ray;
        }

        if (target < nums[mid])
            return binarySearch(nums, l, mid - 1, target);

        else
            return binarySearch(nums, mid + 1, r, target);
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        vector<int> ray = binarySearch(nums, l, r, target);
        if (ray[0] == INT_MAX)
            ray[0] = -1;

        return ray;
    }
};