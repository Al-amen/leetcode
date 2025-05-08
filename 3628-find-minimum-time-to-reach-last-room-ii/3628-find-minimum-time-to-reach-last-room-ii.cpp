class Solution {
    int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
public:
    bool is_valid(int i , int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<vector<int>>> time(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;

        pq.push({0, 0, 0, 0});  // (time, row, col, parity)
        time[0][0][0] = 0;

        while (!pq.empty()) {
            auto [t, i, j, parity] = pq.top();
            pq.pop();

            if (i == n - 1 && j == m - 1)
                return t;

            for (int d = 0; d < 4; d++) {
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];
                if (is_valid(ni, nj, n, m)) {
                    int cost = (parity == 0 ? 1 : 2);

                    int startMoveTime = max(t, moveTime[ni][nj]);
                    int arriveTime = startMoveTime + cost;
                    int nextParity = 1 - parity;

                    if (arriveTime < time[ni][nj][nextParity]) {
                        time[ni][nj][nextParity] = arriveTime;
                        pq.push({arriveTime, ni, nj, nextParity});
                    }
                }
            }
        }

        return -1;
    }
};
