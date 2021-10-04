#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void solve(string &s, int idx, string ans, vector<string> &res)
    {
        if (idx == s.size())
        {
            res.push_back(ans);
            return;
        }

        if (s[idx] >= '0' and s[idx] <= '9')
            solve(s, idx + 1, ans + s[idx], res);
        else
        {
            solve(s, idx + 1, ans + s[idx], res);
            char ch = s[idx];
            if (s[idx] >= 97)
                ch = ch - 32;
            else
                ch = ch + 32;
            solve(s, idx + 1, ans + ch, res);
        }
        return;
    }

    vector<string> letterCasePermutation(string s)
    {
        vector<string> res;
        solve(s, 0, "", res);
        return res;
    }
};