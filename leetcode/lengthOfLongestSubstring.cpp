class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            vector<bool> subS(256);
            for (int j = i; j < n; j++)
            {
                if (subS[s[j]] == true)
                    break;
                else
                {
                    result = max(result, j - i + 1);
                    subS[s[j]] = true;
                }
            }
            subS[s[i]] = false;
        }
        return result;
    }
};