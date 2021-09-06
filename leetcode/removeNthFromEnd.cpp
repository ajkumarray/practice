class Solution
{
public:
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
};