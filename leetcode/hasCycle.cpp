#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *prev = head;
        while (head)
        {
            head = head->next;
            if (head)
                head = head->next;

            if (head == prev)
                return true;

            prev = prev->next;
        }
        return false;
    }
};