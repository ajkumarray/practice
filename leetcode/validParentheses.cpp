#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        unordered_map<char, int> symbols; // = {{'[', -1}, {'{', -2}, {'(', -3}, {']', 1}, {'}', 2}, {')', 3}};
        symbols['{'] = -1;
        symbols['['] = -2;
        symbols['('] = -3;
        symbols['}'] = 1;
        symbols[']'] = 2;
        symbols[')'] = 3;
        stack<char> st;
        for (char bracket : s)
        {
            if (symbols[bracket] < 0)
            {
                st.push(bracket);
            }
            else
            {
                if (st.empty())
                    return false;
                char top = st.top();
                st.pop();
                if (symbols[top] + symbols[bracket] != 0)
                    return false;
            }
        }
        if (st.empty())
            return true;
        return false;
    }
};

int main()
{
    string s;
    cout << "Enter a parentheses string: ";
    cin >> s;
    Solution sol;
    bool valid = sol.isValid(s);
    cout << valid << endl;
    return 0;
}