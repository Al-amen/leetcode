class Solution {
public:
    static bool cmp(vector<int>a, vector<int>b) {
        return a[0] < b[0];
    }
    bool is_overlap(vector<int>a, vector<int>b) {
        if(a[1]>=b[0]) {
            return true;
        }
        return false;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for(int i = 1; i < n; i++) {
            int sz = ans.size()-1;
            if(is_overlap(ans[sz],intervals[i])) {
                int a = min(ans[sz][0],intervals[i][0]);
                int b = max(ans[sz][1],intervals[i][1]);
                ans[sz] = {a,b};
                
            }
            else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
        
    }
};