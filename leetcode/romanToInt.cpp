//  Roman To Integer leetcode problem
//  Created by Ajit Kumar on May07//2021 AD.
//  Copyright © 2021 Ajit Kumar. All rights reserved.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int value(char c)
    {
        if(c == 'I')
            return 1;
        if(c == 'V')
            return 5;
        if(c == 'X')
            return 10;
        if(c == 'L')
            return 50;
        if(c == 'C')
            return 100;
        if(c == 'D')
            return 500;
        if(c == 'M')
            return 1000;
        return -1;
    }
    int romantoInt(string s)
    {
        int result = 0;
        for(auto i = 0; i < s.length(); i++)
        {
            int s1 = value(s[i]);
            if(i+1 < s.length())
            {
                int s2 = value(s[i+1]);
                if(s1 >= s2)
                {
                    result = result + s1;
                }
                else
                {
                    result = result + s2 - s1;
                    i++;
                }
            }
            else
            {
                result = result + s1;
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    int result = solution.romantoInt("MCMXCIV");
    cout << result << endl;
    return 0;
}
