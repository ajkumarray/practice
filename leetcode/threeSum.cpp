class Solution
{
public:
    vector<vector<int> > threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ray;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
            {
                int low = i + 1;
                int high = n - 1;
                int a = 0 - nums[i];
                vector<int> temp;
                while (low < high)
                {
                    if (a == (nums[low] + nums[high]))
                    {
                        temp = {nums[i], nums[low], nums[high]};
                        ray.push_back(temp);

                        while (low < high && nums[low] == nums[low + 1])
                            low++;
                        while (low < high && nums[high] == nums[high - 1])
                            high--;

                        low++;
                        high--;
                    }
                    else if (a > nums[low] + nums[high])
                    {
                        low++;
                    }
                    else
                    {
                        high--;
                    }
                }
            }
        }
        return ray;
    };