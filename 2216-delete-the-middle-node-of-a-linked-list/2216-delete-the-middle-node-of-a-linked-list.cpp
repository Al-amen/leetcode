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
        ListNode* temp = head;
        int n = size(temp);
        cout << n << endl;
        int x = n/2;
        x--;
        
        while(x--) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
        
    }
};