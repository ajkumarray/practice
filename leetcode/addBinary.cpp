#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string c = "";
        int carry = 0, i = 0, j = 0;
        while (i < a.size() || j < b.size() || carry == 1)
        {
            int aNum = i < a.size() ? a[i++] - '0' : 0;
            int bNum = j < b.size() ? b[j++] - '0' : 0;
            c += char((carry ^ aNum ^ bNum) + '0');
            carry = (carry & aNum) | (carry & bNum) | (aNum & bNum);
        }
        reverse(c.begin(), c.end());
        return c;
    }
};

int main()
{
    string a, b;
    cout << "Enter two binary strings: ";
    cin >> a >> b;
    Solution sol;
    string c = sol.addBinary(a, b);
    cout << c << endl;
    return 0;
}