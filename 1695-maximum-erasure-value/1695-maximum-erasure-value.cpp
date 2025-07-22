class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0;
        int max_sum = 0;
        map<int,int> mp;
        
        while(j < n) {
            if(mp[nums[j]] == 0) {
                sum += nums[j];
                mp[nums[j]] = 1;
                max_sum = max(max_sum, sum);
                j++;
            }
            else {
                sum -= nums[i];
                mp[nums[i]] = 0;
                i++;
            }
        }
        return max_sum;
    }
};
