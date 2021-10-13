#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        int n = s.length();
        const int c = 256;
        int count[c] = {0};
        for (int i = 0; i < n; i++)
            count[s[i]]++;
        for (int i = 0; i < n; i++)
        {
            if (count[s[i]] == 1)
                return i;
        }
        return -1;
    }
};