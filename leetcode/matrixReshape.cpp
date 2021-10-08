#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int> > matrixReshape(vector<vector<int> > &mat, int r, int c)
    {
        int mrow = mat.size();
        int mcol = mat[0].size();
        if (mat.size() * mat[0].size() != r * c)
            return mat;

        vector<vector<int> > result(r, vector<int>(c, 0));
        int row = 0, col = 0;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                result[i][j] = mat[row][col];
                if (col == mcol - 1)
                {
                    col = 0;
                    row++;
                }
                else
                    col++;
            }
        }
        return result;
    }
};