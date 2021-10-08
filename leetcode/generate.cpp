#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<vector<int> > generate(int numRows)
    {
        vector<vector<int> > pascals;

        if (numRows >= 1)
            pascals.push_back({1});
        if (numRows >= 2)
            pascals.push_back({1, 1});

        for (int i = 2; i < numRows; i++)
        {
            vector<int> row;
            row.push_back(1);
            for (int j = 1; j < i; j++)
            {
                row.push_back(pascals[i - 1][j] + pascals[i - 1][j - 1]);
            }
            row.push_back(1);
            pascals.push_back(row);
        }
        return pascals;
    }
};