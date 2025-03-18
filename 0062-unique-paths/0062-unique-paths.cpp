class Solution {
public:
   int totalUniquePaths(int i, int j,vector<vector<int>> &dp) {
        if(j == 0 && i == 0)return 1;
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int up = totalUniquePaths(i-1, j,dp);
        int left = totalUniquePaths( i, j-1,dp);
        


        return dp[i][j] = up + left;



   }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,1));
        dp[0][0] = 1;
        for(int i = 1; i < m; i++) {
            for(int j = 1;  j < n; j++) {
                
                int left,up;
                if(i > 0) {
                    up = dp[i-1][j];
                }
                if(j > 0) {
                    left = dp[i][j-1];
                }
                dp[i][j] = up + left;
                
            }
            
        }
        
        return dp[m-1][n-1];
    }
};