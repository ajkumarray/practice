class Solution
{
public:
    //  counting the number of nodes in list and traversing up to the nth node from last

    int getCount(ListNode *head)
    {
        int count = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int count = getCount(head);

        if (n > count)
            return head;

        else if (count == n)
            return head->next;

        else
        {
            int diff = count - n;
            ListNode *prev = NULL;
            ListNode *temp = head;
            for (int i = 0; i < diff; i++)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            return head;
        }
    }

    /*
    2 Pointer Algorithm
*/

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp, *first = head, *second = head;
        for (int i = 0; i < n; i++)
        {
            if (second->next == NULL)
            {
                if (i == n - 1)
                {
                    head = head->next;
                }
                return head;
            }
            second = second->next;
        }
        while (second->next != NULL)
        {
            first = first->next;
            second = second->next;
        }
        first->next = first->next->next;
        return head;
    }
};