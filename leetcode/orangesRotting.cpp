#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int row;
    int col;

    struct ele
    {
        int x, y;
    };

    bool isdelim(ele temp)
    {
        return (temp.x == -1 && temp.y == -1);
    }

    bool isvalid(int i, int j)
    {
        return (i >= 0 && j >= 0 && i < row && j < col);
    }

    bool checkall(vector<vector<int> > &grid)
    {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (grid[i][j] == 1)
                    return true;

        return false;
    }

    int orangesRotting(vector<vector<int> > &grid)
    {
        queue<ele> Q;
        ele temp;
        int ans = 0;

        row = grid.size();
        col = grid[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 2)
                {
                    temp.x = i;
                    temp.y = j;
                    Q.push(temp);
                }
            }
        }

        temp.x = -1;
        temp.y = -1;
        Q.push(temp);

        while (!Q.empty())
        {
            bool flag = false;
            while (!isdelim(Q.front()))
            {
                temp = Q.front();
                if (isvalid(temp.x + 1, temp.y) && grid[temp.x + 1][temp.y] == 1)
                {
                    if (!flag)
                    {
                        ans++;
                        flag = true;
                    }
                    grid[temp.x + 1][temp.y] = 2;
                    temp.x++;
                    Q.push(temp);

                    temp.x--;
                }
                if (isvalid(temp.x - 1, temp.y) && grid[temp.x - 1][temp.y] == 1)
                {
                    if (!flag)
                    {
                        ans++;
                        flag = true;
                    }
                    grid[temp.x - 1][temp.y] = 2;
                    temp.x--;
                    Q.push(temp);
                    temp.x++;
                }
                if (isvalid(temp.x, temp.y + 1) && grid[temp.x][temp.y + 1] == 1)
                {
                    if (!flag)
                    {
                        ans++;
                        flag = true;
                    }
                    grid[temp.x][temp.y + 1] = 2;
                    temp.y++;
                    Q.push(temp);
                    temp.y--;
                }
                if (isvalid(temp.x, temp.y - 1) && grid[temp.x][temp.y - 1] == 1)
                {
                    if (!flag)
                    {
                        ans++;
                        flag = true;
                    }
                    grid[temp.x][temp.y - 1] = 2;
                    temp.y--;
                    Q.push(temp);
                }
                Q.pop();
            }
            Q.pop();
            if (!Q.empty())
            {
                temp.x = -1;
                temp.y = -1;
                Q.push(temp);
            }
        }
        return (checkall(grid)) ? -1 : ans;
    }
};