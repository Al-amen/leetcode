#include <vector>
#include <unordered_set>

using namespace std;

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Create a set from the nums array for quick look-up
        unordered_set<int> valuesToRemove(nums.begin(), nums.end());
        
        // Create a dummy node to handle edge cases more easily
        ListNode dummy(0);
        dummy.next = head;
        ListNode* current = &dummy;
        
        // Traverse the list and remove nodes with values in the set
        while (current->next != nullptr) {
            if (valuesToRemove.find(current->next->val) != valuesToRemove.end()) {
                // Node to delete is found
                ListNode* nodeToDelete = current->next;
                current->next = current->next->next; // Skip the node to delete
                delete nodeToDelete; // Free memory
            } else {
                current = current->next; 
            }
        }
        
        return dummy.next; 
    }
};
