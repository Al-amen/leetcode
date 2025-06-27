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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL )return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        delete slow;
        return head;
        
    }
};