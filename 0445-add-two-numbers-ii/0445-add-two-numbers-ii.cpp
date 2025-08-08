/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* nextptr;

        while(current) {
            nextptr = current->next;
            current->next = prev;
            prev = current;
            current = nextptr;
        }

        return prev;

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* x = reverseList(l1);
        ListNode* y = reverseList(l2);

         ListNode* dummy = new ListNode(0);
         ListNode* current = dummy;
         int carry = 0;

         while(x || y || carry) {

            int val1 = (x? x->val : 0);
            int val2 = (y? y->val : 0);

            int total = val1 + val2 + carry;

            carry = total / 10;

            current->next = new ListNode(total%10);
            current = current->next;

            if(x){
                x  = x->next;
            }
            if(y) {
                y = y->next;
            }
         }

         return (reverseList(dummy->next));
         
    }
};