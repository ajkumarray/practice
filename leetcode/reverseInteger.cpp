//  reverseInteger leetCode ProblEM
//
//  Created by Ajit Kumar on March24//2021 AD.
//  Copyright © 2021 Ajit Kumar. All rights reserved.

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long num = x;
        bool negative = false;
        if(num < 0)
        {
            negative = true;
            num = -num;
        }
        long prevRevNum = 0, revNum = 0;
        while(num != 0)
        {
            int currDigit = num % 10;
            revNum = (revNum * 10) + currDigit;
            if((revNum - currDigit)/10 != prevRevNum)
                return 0;
            prevRevNum = revNum;
            num = num / 10;
        }
        if(revNum > INT_MAX)
            return 0;
        return (negative) ? -revNum : revNum;
    }
};
