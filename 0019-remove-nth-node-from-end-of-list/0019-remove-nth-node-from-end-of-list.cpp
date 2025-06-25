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
        int sz = size(head);
        int ind = sz-n;
        cout << ind << endl;
        if(ind == 0) {
            head = head ->next;
        }
        else {
            ListNode* temp = head;
           for(int i = 1; i < ind; i++) {
                temp = temp->next;
           }
           temp->next = temp->next->next;
        }

        return head;

           
        
    }
};