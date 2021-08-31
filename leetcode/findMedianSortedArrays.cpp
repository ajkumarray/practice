class Solution
{
public:
    void merge(int *nums1, int nums1Size, int *nums2, int nums2Size)
    {
        double ans[nums1Size + nums2Size];
        int i = nums1Size - 1, j = nums2Size - 1, l = nums1Size + nums2Size - 1;
        while (i >= 0 || j >= 0)
        {
            if (i >= 0 && j >= 0)
            {
                ans[l--] = (nums1[i] <= nums2[j]) ? nums2[j--] : nums1[i--];
            }
            else if (i >= 0 && j < 0)
            {
                ans[l--] = nums1[i--];
            }
            else
            {
                ans[l--] = nums2[j--];
            }
        }

        double median = 0;
        if ((nums1Size + nums2Size) % 2 == 0)
        {
            median = ((ans[((nums1Size + nums2Size) / 2) - 1]) + (ans[(((nums1Size + nums2Size) / 2) + 1) - 1])) / 2;
        }
        else
            median = ans[((nums1Size + nums2Size + 1) / 2) - 1];

        return median;
    }
};