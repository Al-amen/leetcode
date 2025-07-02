class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l = 0, r = n-1;
        vector<long long>ans;
        while(l <= r) {
            long long x = nums[l] + nums[r];
            ans.push_back(x);
            
            l++,r--;
        }
        long long x = *max_element(ans.begin(),ans.end());
        return x;
        
        
    }
};