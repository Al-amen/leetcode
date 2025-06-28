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
    int size(ListNode* temp) {
        int cnt = 0;
        while(temp != NULL) {
            cnt++;
            temp = temp->next;

        }

        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
    ListNode* dummy = new ListNode(0);  // Helps handle edge cases
    dummy->next = head;
    ListNode* first = dummy;
    ListNode* second = dummy;

    // Move first pointer n+1 steps ahead
    for (int i = 0; i <= n; i++) {
        first = first->next;
    }

    // Move both pointers until first reaches end
    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }

    // Remove the Nth node from end
    second->next = second->next->next;

    return dummy->next;  // In case head was removed

           
        
    }
};