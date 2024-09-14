class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int mx_element = max_element(nums.begin(), nums.end())-nums.begin();

        int ans = 1, cnt = 0;

        for(auto it : nums) {
            
            if(it == mx_element )cnt++;
            else cnt = 0;
            ans = max(ans,cnt);
        }

        return ans;

        
    }
};