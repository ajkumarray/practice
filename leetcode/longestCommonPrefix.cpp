//  longestCommonPrefix leetcode problem
//
//  Created by Ajit Kumar on May08//2021 AD.
//  Copyright © 2021 Ajit Kumar. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findMinLength(vector<string> ray)
    {
        int min = INT_MAX;
        for(auto i = 0; i <= (ray.size())-1; i++)
            if(ray[i].length() < min)
                min = (int)ray[i].length();
        return min;
    }
    
    bool allContainsPrefix(vector<string> ray, string str, int start, int end)
    {
        for(auto i = 0; i <= (ray.size())-1; i++)
            for(int j = start; j <= end; j++)
                if(ray[i][j] != str[j])
                    return false;
        return true;
    }
    
    string longestCommonPrefix(vector<string>& ray)
    {
        string result = "";
        int low = 0, high = 0;
        high = findMinLength(ray);
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(allContainsPrefix(ray, ray[0], low, mid))
            {
                result = result + ray[0].substr(low, mid-low+1);
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    vector<string> ray;
    ray.push_back("flower");
    ray.push_back("flow");
    ray.push_back("flight");
    Solution solution;
    string result = solution.longestCommonPrefix(ray);
    cout << result << endl;
    return 0;
}
