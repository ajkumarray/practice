//  twoSum LeetCode Problem
//  Created by Ajit Kumar on March24//2021 AD.
//  Copyright © 2021 Ajit Kumar. All rights reserved.

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int flag=0;
        for(auto i=0; i != nums.size();i++)
        {
            for(auto j= i+1;j != nums.size(); j++)
            {
                if((nums[i]+nums[j]) == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    flag=1;
                }
                if(flag == 1)
                    break;
            }
            if(flag == 1)
                break;
        }
        return result;
    }
};

