class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int max_val = *max_element(nums.begin(),nums.end());

        int ans = 1;
        int cnt = 0;

        for(int x: nums) {
            if(x == max_val) {
                cnt++;
                ans = max(ans,cnt);
            }
            else {
                cnt = 0;
            }
        }
        return ans;
    }
};