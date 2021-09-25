#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        stringstream ss(s);
        string ray = "", word;
        while (ss >> word)
        {
            reverse(word.begin(), word.end());
            ray += ray + word + " ";
        }
        for (int i = 0; i < s.length() - 1; i++)
            s[i] = s[i];
        return ray;
    }
};

int main()
{
    cout << "Enter a string: ";
    string s;
    getline(cin, s);
    Solution sol;
    s = sol.reverseWords(s);
    cout << s << endl;
    return 0;
}
