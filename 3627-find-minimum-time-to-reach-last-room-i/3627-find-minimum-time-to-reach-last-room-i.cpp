class Solution {
    int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
public:
     int is_valid(int i , int j, int n, int m) {
        return i>=0 && i<n && j>= 0 && j<m;
     }
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        int res = 0;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>pq;
        vector<vector<int>>times(n,vector<int>(m,INT_MAX));
        pq.push({0,0,0});
        times[0][0] = 0;
        while(!pq.empty()) {
            auto[t,i,j] = pq.top();
            pq.pop();

            if(i == n-1 and j == m-1)return t;

            for(int d = 0; d < 4; d++) {
                int nr = dirs[d][0] + i;
                int nc = dirs[d][1] + j;
                if(is_valid(nr,nc,n,m)){
                    int time = max(t,moveTime[nr][nc]) + 1;
                    if(time < times[nr][nc]) {
                        times[nr][nc] = time;
                        pq.push({time,nr,nc});
                    }

                }
                
                
            }
        }
        return -1;
    }
    
};