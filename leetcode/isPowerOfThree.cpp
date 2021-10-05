#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;
        n = abs(n);
        while (n % 3 == 0)
            n /= 3;
        return n == 1;
    }
};