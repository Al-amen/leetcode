constexpr int d[5] = {1, 1, -1, -1, 1};//(1,1),(1,-1),(-1, -1),(-1, 1)
int dp[500][500][4][2];
class Solution {
public:
    int n, m;
    bool isOutSide(int i, int j) { 
        return i<0 || i>=n || j<0 || j>=m; 
    }
    int dfs(int i, int j, int dir, bool turn, int nxt, vector<vector<int>>& grid) {
        if (dp[i][j][dir][turn]!=-1) return dp[i][j][dir][turn];
        
        int ans=1, x=grid[i][j];

        // Move in the current direction
        int s=i+d[dir], t=j+d[dir+1];
        if (!isOutSide(s, t)) { 
            int y=grid[s][t];
            if (nxt==y)  // continue moving in the same diagonal
                ans=max(ans, 1+dfs(s, t, dir, turn, nxt^2, grid));
        }

        // Try turning to the next diagonal direction
        if (!turn) { 
            const int newDir=(dir+1)&3;// same %4
            int u=i+d[newDir], v=j+d[newDir+1];
            if (!isOutSide(u, v)) {
                const int z=grid[u][v];
                if (nxt==z)  // to turn to the next diagonal
                    ans=max(ans, 1+dfs(u, v, newDir, 1, nxt^2, grid));
            }
        }

        return dp[i][j][dir][turn]=ans;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n=grid.size(), m=grid[0].size();
        
        for (int i=0; i<n; i++)// fill dp 
            for(int j=0; j<m; j++)
                memset(dp[i][j], -1, sizeof(dp[i][j]));

        int ans=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j]==1) { // Start from cells that are part of the path
                    for (int d=0; d<4; d++) 
                        ans=max(ans, dfs(i, j, d, 0, 2,  grid));
                }
            }
        }
        return ans;
    }
};