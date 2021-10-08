#include <bits/stdc++.h>

using namespace std;

class MyQueue
{
public:
    stack<int> s;
    MyQueue()
    {
        stack<int> temp;
        s = temp;
    }

    void push(int x)
    {
        stack<int> as;
        while (!s.empty())
        {
            as.push(s.top());
            s.pop();
        }
        s.push(x);
        while (!as.empty())
        {
            s.push(as.top());
            as.pop();
        }
    }

    int pop()
    {
        if (!s.empty())
        {
            int ans = s.top();
            s.pop();
            return ans;
        }
        return -1;
    }

    int peek()
    {
        return s.top();
    }

    bool empty()
    {
        return (s.empty());
    }
};