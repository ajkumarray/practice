#include <bits/stdc++.h>

using namespace std;

class Student
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        //  recursive method

        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        ListNode *head;
        if (l1->val < l2->val)
        {
            head = l1;
            head->next = mergeTwoLists(l1->next, l2);
        }
        else
        {
            head = l2;
            head->next = mergeTwoLists(l1, l2->next);
        }
        return head;
    }
};

/*
    //  exceeds time limit


        ListNode *head1 = l1;
        ListNode *head2 = l2;
        ListNode *temp = new node(-1);
        ListNode *head3 = temp;

        while (head1 != NULL && head2 != NULL)
        {
            if (head1->val < head2->val)
            {
                head3->next = head1;
                head1 = head1->next;
            }
            else
            {
                head3->next = head2;
                head2 = head2->next;
            }
            head3 = head3->next;
        }
        while (head1 != NULL)
        {
            head3->next = head1;
            //head1 = head1->next;
            //head3 = head3->next;
        }

        while (head2 != NULL)
        {
            head3->next = head2;
            //head2 = head2->next;
            //head3 = head3->next;
        }

        return temp->next;
*/