class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();

        vector<pair<int,int>>vp;
        for(int i = 0; i < n; i++) {
            vp.push_back({i,nums[i]});
        }
        auto lamda = [](pair<int,int>p1, pair<int,int>p2) {
            return p1.second > p2.second;
        };
        
        sort(vp.begin(),vp.end(),lamda);
        
        sort(vp.begin(),vp.begin()+k);
        vector<int>ans;
        for(auto it: vp) {
            if(k  == 0)break;
            ans.push_back(it.second);
            k--;
        }
        return ans;

    }
};