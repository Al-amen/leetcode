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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>, greater<int> >minHeap;

        for(auto list: lists) {
            while(list != nullptr) {
                minHeap.push(list->val);
                list = list->next;
            } 
        }

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while(!minHeap.empty()) {
            current ->next = new ListNode(minHeap.top());
            minHeap.pop();
            current = current->next;
        }

        return dummy->next;

        
    }
};