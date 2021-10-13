#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int guessNumber(int n)
    {
        int beg = 1, end = n;
        while (beg <= end)
        {
            int num = beg + (end - beg) / 2;
            if (guess(num) == 0)
                return num;
            if (guess(num) < 0)
                end = num - 1;
            else
                beg = num + 1;
        }
        return 0;
    }
};