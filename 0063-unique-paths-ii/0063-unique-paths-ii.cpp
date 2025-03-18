class Solution {
public:
    int total_uniquePathsWithObstacles(vector<vector<int>> & obstacleGrid,int i, int j,vector<vector<int>> &dp) {
        if(i >= 0 && j>=0 && obstacleGrid[i][j] == 1)return 0;
        if(i == 0 && j == 0)return 1;
        if(i < 0 || j < 0)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int up = total_uniquePathsWithObstacles(obstacleGrid,i-1,j,dp);
        int left = total_uniquePathsWithObstacles(obstacleGrid,i,j-1,dp);

        return dp[i][j] =  up + left;
        
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0] = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(obstacleGrid[i][j] == 1)dp[i][j] = 0;
                else {
                     int up = (i > 0) ? dp[i-1][j] : 0;  // Paths from top
                    int left = (j > 0) ? dp[i][j-1] : 0; // Paths from left
                    if (i != 0 || j != 0) { // Skip the start position
                        dp[i][j] = left + up;
                    }


                }
                
               
            }
        }
        return dp[m-1][n-1];

    }
};