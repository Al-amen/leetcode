class Solution {
private:
    int f(int n , int pos, vector<int>&nums, vector<int>&dp) {
        if (pos >= n-1)return 0;
        if(dp[pos] != -1)return dp[pos];
        int minStep = 1e5+7;
        for(int j = 1; j<=nums[pos]; j++) {
            int step = 1 + f(n,pos+j,nums,dp);
            minStep = min(minStep,step);
        }
        return dp[pos] = minStep;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return f(n,0,nums,dp);
    }
};