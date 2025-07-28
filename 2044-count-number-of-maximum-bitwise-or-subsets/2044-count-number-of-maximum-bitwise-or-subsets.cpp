class Solution {
public:
    int f(int n, int i, int currentOr , int target, vector<int>&nums,vector<vector<int>> &dp ) {
        if(i == n) {
            return currentOr == target ? 1: 0;
        }

        if(dp[i][currentOr] != -1) return dp[i][currentOr];
        int notTake =  f(n, i+1, currentOr,target, nums, dp);
        int take = f(n,i+1, currentOr | nums[i], target, nums, dp);

        
        return dp[i][currentOr] = take + notTake;


    }
    int countMaxOrSubsets(vector<int>& nums) {
        
        int n = nums.size();
        
        int maxOrValue = 0;

        for(auto num: nums)  maxOrValue |= num;

        vector<vector<int>> dp(n, vector<int>(maxOrValue+1,-1));

        return f(n,0,0,maxOrValue,nums,dp);

        
        

    }
};