#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t num = 0, temp = 0;
        for (int i = 0; i < 32; i++)
        {
            temp = n & 0x01;
            num |= temp << (31 - i);
            n >>= 1;
        }
        return num;
    }
};