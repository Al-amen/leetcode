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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ansNode = new ListNode(0);
        ListNode* currentNode = ansNode;
       
       ListNode* ptr = head->next;
       int cnt = 0;
       int sum = 0;
       while(ptr != NULL) {
          
          if(ptr->val == 0) {
            ListNode* new_node = new ListNode(sum);
            currentNode->next = new_node;
            currentNode = new_node;
            sum = 0;
          }
    
          else {
            sum += ptr->val;
          }


          ptr = ptr->next;
       }
       return ansNode->next;
    }
       
};