class Solution
{
    public:
        int dirs[8][2] = {
		    {0,-1},
            {0,1},
            {-1,0},
            {1,0},
            {-1,-1},
            {1,1},
            {1,-1},
            {-1,1}

        };
    bool is_safe(int nrow,int ncol, int n,int m) {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m;
    }
    int shortestPathBinaryMatrix(vector<vector < int>> &grid)
    {
        int n = grid.size();
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        queue<pair<pair<int,int>,int>>q;
        if(grid[0][0] != 0 or grid[n-1][n-1] != 0) {
            return -1;
        }
        q.push({{0,0},1});
        vis[0][0] = true;
        int len = 0;
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int path_len = q.front().second;
            q.pop();
            if(row == n-1 && col == n-1) {
                return path_len;
            }
            for(int i = 0; i < 8; i++) {
                int nrow = row + dirs[i][0];
                int ncol = col + dirs[i][1];
                
                if(is_safe(nrow,ncol,n,n) && !vis[nrow][ncol] && grid[nrow][ncol] == 0) {
                    vis[nrow][ncol] = true;
                    q.push({{nrow,ncol},path_len+1});
                    
                }
            }
        }
        
        return -1;
    }
};