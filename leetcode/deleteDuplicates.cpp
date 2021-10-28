#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    //      sorted list I
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
            return head;

        if (head->next == NULL)
        {
            head->next = deleteDuplicates(head->next);
        }
        else
        {
            if (head->val == head->next->val)
            {
                if (head->next->next == NULL)
                {
                    head->next = NULL;
                }
                else
                    head->next = head->next->next;
                head = deleteDuplicates(head);
            }
            else
                head->next = deleteDuplicates(head->next);
        }

        return head;
    }

    //      sorted list II
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
            return head;

        if (head->next == NULL)
        {
            head->next = deleteDuplicates(head->next);
        }
        else
        {
            if (head->val == head->next->val)
            {
                if (head->next->next == NULL)
                {
                    head = NULL;
                }
                else
                    head = head->next->next;
                head = deleteDuplicates(head);
            }
            else
                head->next = deleteDuplicates(head->next);
        }

        return head;
    }
};