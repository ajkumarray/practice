#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int num, ndog, ncat, add;
        cin >> num >> ndog >> ncat >> add;
        string s;
        cin >> s;
        int i = 0;
        while (ndog >= 0 && ncat >= 0 && i < num)
        {
            if (s[i] == 'D')
            {
                ndog--;
                ncat += add;
                // num--;
                i++;
            }
            else if (s[i] == 'C')
            {
                ncat--;
                // num--;
                i++;
            }
        }
        string ans = "NO";
        if (ndog == 0)
            ans = "YES";
        cout << "Case #" << (k + 1) << ": " << ans << endl;
    }
    return 0;
}