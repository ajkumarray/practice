class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> ray;
        for(auto i = nums.begin(); i != nums.end(); i++)
        {
            int sq = *i * *i;
            ray.push_back(sq);
        }
        sort(ray.begin(), ray.end());
        return ray;
    }
}