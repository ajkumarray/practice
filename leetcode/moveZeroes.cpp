class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int count = 0;
        for (auto i = nums.begin(); i != nums.end(); i++)
        {
            if ((*i) == 0)
            {
                nums.erase(i);
                i--;
                count++;
            }
        }

        for (int i = 0; i < count; i++)
            nums.push_back(0);
    }
};
