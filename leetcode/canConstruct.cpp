#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        map<char, int> m;
        for (int i = 0; i < magazine.size(); i++)
        {
            m[magazine[i]]++;
        }

        for (int i = 0; i < ransomNote.size(); i++)
        {
            if (m[ransomNote[i]] >= 1)
            {
                m[ransomNote[i]]--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};