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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* ptr = head;
        vector<int>v;
        int ind = 1;
        while(ptr != NULL) {
             ind++;
            ListNode* first = ptr;

            if(ptr and ptr->next) {
                 ListNode* second = ptr->next;

                 if(ptr->next->next){
                    ListNode* third = ptr->next->next;

                    if(second->val > first->val && second->val > third->val) {  
                        v.push_back(ind);
                }
                else if(second->val < first->val && second->val < third->val) {
                      v.push_back(ind);
                }

              }

            }
           
                
            ptr = ptr->next;
            
        }
        if (v.empty() || v.size()==1){
            v.clear();
            v.push_back(-1);
             v.push_back(-1);

            return v;
        }
        int n = v.size();
        
        int mx = v[n-1] - v[0];
        if(n == 2) {
            v[0] = mx;
            v[1] = mx;
            return v;
        }
        int mini = 105+6;
        for(int i = 1; i < n; i++) {
            
                mini = min(mini, v[i]-v[i-1]);          
        }
        v.clear();
        v.push_back(mini);
         v.push_back(mx);
        return v;
    }
};