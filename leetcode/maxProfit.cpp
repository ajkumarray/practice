#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int curr = INT_MAX;
        int profit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            curr = min(prices[i], curr);
            profit = max(prices[i] - curr, profit);
        }
        return profit;
    }
};