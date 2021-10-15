#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    //  without cooldown
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

    //  with cooldown
    int sol(vector<int> &prices)
    {
        int ray[3][2];
        for (int i = 0; i <= 2; i++)
            for (int j = 0; j <= 1; j++)
                ray[i][j] = 0;

        for (int day = (int)prices.size() - 1; day >= 0; day--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int &ans = ray[day % 3][buy];
                int ans1 = ray[(day + 1) % 3][buy];
                int ans2 = 0;
                if (buy)
                    ans2 = -prices[day] + ray[(day + 1) % 3][0];
                else
                    ans2 = prices[day] + ray[(day + 2) % 3][1];

                ans = max(ans1, ans2);
            }
        }
        return ray[0][1];
    }

    int maxProfit(vector<int> &prices)
    {
        int ans = 0;
        ans = sol(prices);
        return ans;
    }
};