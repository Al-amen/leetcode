class Solution {
public:
    int f(int n, int ind, int prev, const vector<int>& arr, vector<vector<int>>& dp) {
        if (ind >= n) return 0;
        if (dp[prev + 1][ind] != -1) return dp[prev + 1][ind];

        int len = f(n, ind + 1, prev, arr, dp); // not pick

        if (prev == -1 || arr[ind] > arr[prev]) {
            len = max(len, 1 + f(n, ind + 1, ind, arr, dp)); // pick
        }

        return dp[prev + 1][ind] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return f(n, 0, -1, nums, dp);
    }
};
