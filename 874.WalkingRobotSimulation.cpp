class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
         unordered_set<string> obs;
        for (auto& obstacle : obstacles) {
            obs.insert(to_string(obstacle[0]) + "," + to_string(obstacle[1]));
        }

        int x = 0, y = 0, dx = 0, dy = 1;
        int ans = 0;

        for (int c : commands) {
            if (c == -1) { 
                int temp = dx;
                dx = dy; dy = -temp;
            } else if (c == -2) { 
                int temp = dx;
                dx = -dy; dy = temp;
            } else {
  
                for (int i = 0; i < c; ++i) {
                    int xx = x + dx;
                    int yy = y + dy;

                    if (obs.find(to_string(xx) + "," + to_string(yy)) != obs.end()) break; 
                    x = xx;
                    y = yy;
                    ans = max(ans, x * x + y * y); 
                }
            }
        }

        return ans;
        
    }
};