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
        vector<vector<int>>dp(m,vector<int>(n,-1));

        return path_sum(grid,m-1,n-1,dp);

    }
};