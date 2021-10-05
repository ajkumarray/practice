#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        for (int i = 0; i <= n / 2 && i < 15.5; i++)
        {
            int mul = pow(4, i);
            if (mul == n)
                return true;
        }
        return false;
    }
};