class Solution {
public:
    bool f(vector<int>& nums, int i, int target, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (i == 0) return nums[0] == target;
        if (dp[i][target] != -1) return dp[i][target];

        bool notTake = f(nums, i - 1, target, dp);
        bool take = false;
        if (nums[i] <= target) {
            take = f(nums, i - 1, target - nums[i], dp);
        }

        return dp[i][target] = notTake || take;
    }
    
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int k = accumulate(nums.begin(), nums.end(), 0);
        
        if (k % 2 != 0) return false;
        k = k / 2;
        
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return f(nums, n - 1, k, dp);
    }
};
