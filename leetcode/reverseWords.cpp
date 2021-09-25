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
            //cout << word << endl;
            reverse(word.begin(), word.end());
            cout << word << endl;
            ray = ray + word + " ";
        }
        return ray;
    }
};

int main()
{
    cout << "Enter a string: ";
    string s;
    cin >> s;
    Solution sol;
    s = sol.reverseWords(s);
    cout << s << endl;
    return 0;
}
