class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size())
            return false;
        int n1 = s1.size();
        vector<int> map1(26, 0);
        for (auto c : s1)
        {
            map1[c - 'a'] += 1;
        }
        for (auto i = 0; i <= s2.size() - n1; ++i)
        {
            vector<int> map2(26, 0);
            for (auto j = i; j < i + n1; ++j)
            {
                map2[s2[j] - 'a'] += 1;
            }
            if (map1 == map2)
                return true;
        }
        return false;
    }
}