class Solution {
 public:
    int f(vector<int>&coins,int n, int target, vector<vector<int>>&dp) {
        if(n == 0) {
            return (target%coins[0] == 0);
            
        }
        if(dp[n][target] != -1)return dp[n][target];
    
        int notTake = f(coins,n-1,target,dp);
        int take = 0;
        if(coins[n]<=target) {
            take =  f(coins,n,target-coins[n],dp);
        }
    
        return dp[n][target] = take + notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(coins, n-1, amount, dp);
    }
};