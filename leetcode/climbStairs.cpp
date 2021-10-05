#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        int s1 = 1, s2 = 1;
        for (int i = 2; i <= n; i++)
        {
            s2 = s1 + s2;
            s1 = s2 - s1;
        }
        return s2;
    }
};