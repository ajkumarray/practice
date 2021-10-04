#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int> > result;
    void combineUtil(int n, int k, int x, vector<int> temp, int count)
    {
        if (count == k)
        {
            result.push_back(temp);
            return;
        }
        if (count > k)
            return;

        for (int i = x; i <= n; i++)
        {
            temp.push_back(i);
            combineUtil(n, k, i + 1, temp, count + 1);
            temp.pop_back();
        }
    }

    vector<vector<int> > combine(int n, int k)
    {
        combineUtil(n, k, 1, {}, 0);
        return result;
    }
};