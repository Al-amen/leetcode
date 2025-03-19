class Solution {


public:
   int path_sum(vector<vector<int>> & triangle, int i, int j,int n, vector<vector<int>> &dp) {
       if(i == n-1) return triangle[n-1][j];
       if(dp[i][j] != -1)return dp[i][j];
       int d = triangle[i][j] + path_sum(triangle,i+1,j,n,dp);
       int dg = triangle[i][j] + path_sum(triangle,i+1,j+1,n,dp);

       return dp[i][j] = min(d,dg);

       
   }
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return path_sum(triangle,0,0,n,dp);
        
    }
};