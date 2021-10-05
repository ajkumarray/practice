#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        for (int i = 0; i <= n / 2 && i < 31; i++)
        {
            int mul = pow(2, i);
            if (mul == n)
                return true;
        }
        return false;
    }
};