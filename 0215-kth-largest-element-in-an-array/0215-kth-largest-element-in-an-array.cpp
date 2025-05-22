class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq(nums.begin(),nums.end());

        k--;
        while(k--) {
            pq.pop();
        }
        cout << pq.top();

        return pq.top();
        
    }
};