class Solution {

public:
   int path_sum(vector<vector<int>> & grid, int i,int j,vector<vector<int>> &dp){
       
       if(i == 0 && j == 0) return grid[0][0];
       if(i < 0 || j < 0)return 100000;
       if(dp[i][j] != -1)return dp[i][j];
       int up = grid[i][j] + path_sum(grid,i-1,j,dp);
       int left = grid[i][j] + path_sum(grid,i,j-1,dp);
      return dp[i][j] = min(left,up);


   }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0){
                    dp[i][j] = grid[0][0];
                }
                else {
                    int up = (i > 0) ? dp[i-1][j] : INT_MAX;
                    int left = (j > 0) ? dp[i][j-1] : INT_MAX;
                    dp[i][j] = grid[i][j] + min(up, left);

                }
                
            }
        }

        return dp[m-1][n-1];

    }
};