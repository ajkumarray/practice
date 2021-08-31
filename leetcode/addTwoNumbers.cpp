class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(0);
        ListNode *temp = head;
        int carry = 0, value;

        while (l1 != NULL || l2 != NULL)
        {
            int a = 0, b = 0;
            if (l1)
            {
                a = l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                b = l2->val;
                l2 = l2->next;
            }
            value = a + b + carry;
            carry = value / 10;

            ListNode *nextnode = new ListNode(value % 10);

            temp->next = nextnode;
            temp = temp->next;
        }
        if (carry)
        {
            ListNode *nextnode = new ListNode(carry % 10);
            carry /= 10;

            temp->next = nextnode;
            temp = temp->next;
        }

        return head->next;
    }
};