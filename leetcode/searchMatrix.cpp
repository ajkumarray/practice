#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target)
    {
        int m = matrix.size() - 1, n = matrix[0].size() - 1;
        int top = 0, last = m;
        int mid = top + (last - top) / 2;

        if ((matrix[0][0] > target) || (matrix[m][n] < target))
            return false;

        while (top <= last)
        {
            mid = top + (last - top) / 2;
            if (matrix[mid][0] == target)
                return true;

            if (matrix[mid][0] < target)
                top = mid + 1;
            else
                last = mid - 1;
        }
        mid = matrix[mid][0] > target ? mid - 1 : mid;
        int row = mid;
        top = 0;
        last = n;
        mid = top + (last - top) / 2;
        while (top <= last)
        {
            mid = top + (last - top) / 2;
            if (matrix[row][mid] == target)
                return true;

            if (matrix[row][mid] < target)
                top = mid + 1;
            else
                last = mid - 1;
        }
        return false;
    }
};