class Solution {
public:
    int dirs[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
    bool is_safe(int nrow, int ncol, int n, int m) {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m;
     }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,    greater<pair<int,pair<int,int>>>>q;
    
        q.push({0,{0,0}});
       
        int len = 0;
        while(!q.empty()) {
            auto it = q.top();
            int diff = it.first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();
            if(row == n-1 && col == m-1) {
                return diff;
            }
            for(int i = 0; i < 4; i++) {
                int nrow = row + dirs[i][0];
                int ncol = col + dirs[i][1];
                
                if(is_safe(nrow,ncol,n,m)) {
                    int nEffort = max(abs(heights[nrow][ncol] - heights[row][col]),diff);
                    if(nEffort < dist[nrow][ncol]) {
                        q.push({nEffort,{nrow,ncol}});
                        dist[nrow][ncol] = nEffort;
                    }
                    
                }
            }
        }
        return 0;
    }
};