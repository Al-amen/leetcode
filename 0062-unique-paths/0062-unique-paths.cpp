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
        vector<vector<int>>dp(m,vector<int>(n,-1));
        
        return totalUniquePaths(m-1,n-1,dp);
    }
};