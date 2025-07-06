/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pointerA = headA;
        ListNode* pointerB = headB;

        while(pointerA != pointerB) {
            if(pointerA == NULL) {
                pointerA = headB;
            }
            else {
                pointerA = pointerA->next;
            }
            if(pointerB == NULL) {
                pointerB = headA;
                
            }
            else {
                pointerB = pointerB->next;
            }


        }
        return pointerB;
        
    }
};