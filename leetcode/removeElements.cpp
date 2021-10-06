#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    ListNode *reverseList(ListNode *head, int val)
    {
        if (!head)
            return head;

        ListNode *temp = head;
        while (temp && temp->next)
        {
            if (temp->next->val == val)
            {
                temp->next = temp->next->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        if (head->val == val)
            head = head->next;

        return head;
    }
};