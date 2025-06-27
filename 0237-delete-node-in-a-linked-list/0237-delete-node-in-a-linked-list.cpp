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
    void deleteNode(ListNode* node) {
       // 1 → 2 → 3 → 4 → 5
    node->val = node->next->val;         // Step 1: copy 4 into 3
    ListNode* temp = node->next;         // Step 2: save pointer to node 4
    node->next = node->next->next;       // Step 3: bypass node 4
    delete temp;                         

        
    }
};