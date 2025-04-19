class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {

        long long ans = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0; i<nums.size(); i++ ){
            int minVal = lower - nums[i];
            int maxVal = upper - nums[i];

            auto leftBound = lower_bound(nums.begin()+i+1, nums.end(),minVal);
            auto rightBound = upper_bound(nums.begin()+i+1, nums.end(),maxVal);

            ans += (rightBound-leftBound);
        }

        return ans;
        
    }
};