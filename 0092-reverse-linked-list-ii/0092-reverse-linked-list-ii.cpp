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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode* dummy = new ListNode(0);

        dummy->next = head;
        ListNode* prev = dummy;

        for(int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }

        ListNode* current = prev->next;
        
        

        for(int i = 0; i < right-left; i++) {
            ListNode* nextptr = current->next;
            current->next = nextptr->next;
            nextptr->next = prev->next;
            prev->next = nextptr;
        }
       

        return dummy->next;
    }
};