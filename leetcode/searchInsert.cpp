class Solution
{
public:
    int binarySearch(vector<int> &nums, int l, int r, int target)
    {
        int mid;
        if (l <= r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;

            if (nums[mid] < target)
            {
                l = mid + 1;
                return binarySearch(nums, mid + 1, r, target);
            }
            return binarySearch(nums, l, mid - 1, target);
        }
        return l;
    }

    int searchInsert(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size();
        if (target > nums[r - 1])
            return r;
        if (target <= nums[l])
            return 0;
        return binarySearch(nums, l, r - 1, target);
    }
};