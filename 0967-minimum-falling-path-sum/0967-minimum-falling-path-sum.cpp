class Solution {
public:
    int minSum(vector<vector<int>>& matrix, int i , int j, vector<vector<int>>& dp) {
        int n = matrix.size();
        if (j < 0 || j >= n) return 1e8; // Out of bounds case
        if (i == 0) return matrix[0][j];  // Base case

        if (dp[i][j] != 1e8) return dp[i][j];  // Memoization check

        int up = matrix[i][j] + minSum(matrix, i - 1, j, dp);
        int leftUp = matrix[i][j] + minSum(matrix, i - 1, j - 1, dp);
        int rightUp = matrix[i][j] + minSum(matrix, i - 1, j + 1, dp);

        return dp[i][j] = min({up, leftUp, rightUp});
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e8));  // Initialize DP with 1e9
        int minPathSum =  1e8;

        for (int j = 0; j < n; j++) {
            minPathSum = min(minPathSum, minSum(matrix, n - 1, j, dp)); // Start from last row
        }
        return minPathSum;
    }
};
