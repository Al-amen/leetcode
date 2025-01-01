class Solution {
public:
    bool is_safe(int nrow, int ncol, int n , int m) {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>dist(n, vector<int>(m,0));
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    q.push({{i,j},0});
                    vis[i][j] = true;
                }
            }
        }
        int dirs[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[row][col] = steps;
            for(int i = 0; i < 4; i++) {
                int nrow = row + dirs[i][0];
                int ncol = col + dirs[i][1];

                if(is_safe(nrow,ncol,n,m) && !vis[nrow][ncol] && mat[nrow][ncol] == 1) {
                     vis[nrow][ncol] = true;
                     q.push({{nrow,ncol},steps+1});
                }
            }


        }
        return dist;
    }
};