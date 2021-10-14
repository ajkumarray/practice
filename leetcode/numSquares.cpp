#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> ray(n + 1, INT_MAX);
        ray[0] = 0;
        int count = 1;
        while (count * count <= n)
        {
            int square = count * count;
            for (int i = square; i < n + 1; i++)
                ray[i] = min(ray[i - square] + 1, ray[i]);

            count++;
        }
        return ray[n];
    }
};