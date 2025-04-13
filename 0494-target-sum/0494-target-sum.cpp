class Solution {
public:

int f(vector<int>& arr, int ind, int target, vector<vector<int>>& dp) {
    if (ind == 0) {
        if (target == 0 && arr[0] == 0) return 2;  // include and exclude zero
        if (target == 0 || target == arr[0]) return 1;
        return 0;
    }

    if (dp[ind][target] != -1) return dp[ind][target];

    int notTake = f(arr, ind - 1, target, dp) ;
    int take = 0;
    if (arr[ind] <= target) {
        take = f(arr, ind - 1, target - arr[ind], dp) ;
    }

    return dp[ind][target] = (take + notTake) ;
}
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if ((total - target) < 0 || (total - target) % 2 != 0) return 0;
        
        int x = (total - target) / 2;
        vector<vector<int>> dp(n, vector<int>(x + 1, -1));
        
        return f(nums, n - 1, x, dp);
    }
};