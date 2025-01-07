class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long prefix = 1;
        long long sufix = 1;
        long long ans = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(prefix == 0) prefix = 1;
            if(sufix == 0)sufix = 1;

            prefix = prefix * nums[i];
            sufix = sufix * nums[n-1-i];
            ans = max(ans,max(prefix,sufix));
        }
        return ans;
    }
};