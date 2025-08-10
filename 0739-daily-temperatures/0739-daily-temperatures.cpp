class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stp;
        int n = temperatures.size();
        vector<int>ans(n,0);
        for(int i = n-1; i>= 0; i--) {
            while(!stp.empty() && stp.top().first <= temperatures[i]) {
                stp.pop();
            }
            if (!stp.empty()) {
                ans[i] = stp.top().second - i;
            }
            stp.push({temperatures[i],i});
        }

        return ans;


        
    }
};