class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        int max_point = 0;
        int ans = 1;

        if(n<=2)return n;

        for(int i = 0; i < n; i++) {
            
            map<double,int>mp;
            
            for(int j = i+1; j < n; j++) {
                
                double x = (double)(points[j][1] - points[i][1]) / (double)(points[j][0] - points[i][0]);
                if(points[j][1] - points[i][1] < 0 && (points[j][0] - points[i][0]) == 0) { // perpendicular
                    mp[abs(x)]++; 
                }
                else mp[x]++;

            }
            int temp = 0;

            for(auto it: mp) {
                temp = max(temp,it.second+1);
            }
            ans = max(temp,ans);
        }
        return ans;
        
    }
};