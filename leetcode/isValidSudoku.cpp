#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        int len = board.size();
        vector<unordered_set<char> > rows(len, unordered_set<char>());
        vector<unordered_set<char> > cols(len, unordered_set<char>());
        vector<unordered_set<char> > boxes(len, unordered_set<char>());
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                int cur_box = (i / 3) * 3 + j / 3;
                char cur_char = board[i][j];
                if (cur_char == '.')
                    continue;
                if (rows[i].count(cur_char))
                {
                    return false;
                }
                rows[i].insert(cur_char);
                if (cols[j].count(cur_char))
                {
                    return false;
                }
                cols[j].insert(cur_char);
                if (boxes[cur_box].count(cur_char))
                {
                    return false;
                }
                boxes[cur_box].insert(cur_char);
            }
        }
        return true;
    }
};