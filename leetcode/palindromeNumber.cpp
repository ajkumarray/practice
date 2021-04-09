//  palindromeNumber LeetCode Problem
//  Created by Ajit Kumar on April08//2021 AD.
//  Copyright © 2021 Ajit Kumar. All rights reserved.

#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if(x < 0)
            return false;
        else
        {
            long num = x, rev = 0;
            do
            {
                int digit = num % 10;
                rev = (rev * 10) + digit;
                num = num / 10;
            }
            while(num != 0);
            if(x == rev)
                
                return true;
        }
        return false;
    }
};


void sol()
{
    int n;
    cin >> n;
    Solution solution;
    bool ans = solution.isPalindrome(n);
    cout << ans << endl;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);           //this method is used for fast I/O in C++
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
    return 0;
}

