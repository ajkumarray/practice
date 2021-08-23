#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        int left = 1, right = x;
        if (x < 2)
            return x;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (mid * mid == x)
                return mid;
            else if (mid * mid > x)
            {
                right = mid;
            }
            else if (mid * mid < x)
            {
                left = mid + 1;
            }
        }
        return left - 1;
    }
};

int main()
{
    int x;
    cout << "Enter a number: ";
    cin >> x;
    Solution sol;
    int result = sol.mySqrt(x);
    cout << result << endl;
    return 0;
}