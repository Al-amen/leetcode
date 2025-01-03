class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r  = 0;
        int min_len = INT_MAX;
        int sum = 0;
        while(r < n) {
            sum += nums[r];
            while(sum >= target) {
                sum -= nums[l];
                min_len = min(min_len, r - l + 1);
                l++;
            }
            r++;
        }
       
        return min_len != INT_MAX ? min_len:0;
    }
};