class Solution {
public:
    bool is_safe(int nrow, int ncol , int n, int m) {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m ; j++) {
                if(i == 0 || i == n-1 || j == 0 || j == m-1) {
                    if(grid[i][j] == 1) {
                        q.push({i,j});
                        vis[i][j]=true;
                    }
                }
            }
        }
        int dirs[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nrow = row + dirs[i][0];
                int ncol = col + dirs[i][1];
                if(is_safe(nrow,ncol, n,m) && !vis[nrow][ncol] and grid[nrow][ncol] == 1) {
                    vis[nrow][ncol] = true;
                    q.push({nrow,ncol});
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <m; j++) {
                if(!vis[i][j]  && grid[i][j] == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};