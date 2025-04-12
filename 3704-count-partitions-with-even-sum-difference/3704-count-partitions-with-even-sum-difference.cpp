class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        vector<int>prefix(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }

        int total = prefix[n-1];
        for(int i = 0 ;i < n-1; i++) {
            if(prefix[i]%2 == (total-prefix[i])%2)cnt++;
        }
        return cnt;
        
    }
};