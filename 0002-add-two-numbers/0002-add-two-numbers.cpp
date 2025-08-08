class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int val1 = (l1 ? l1->val : 0);
            int val2 = (l2 ? l2->val : 0);

            int total = val1 + val2 + carry;
            carry = total / 10;

            current->next = new ListNode(total % 10);
            current = current->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return dummy->next;
    }
};
