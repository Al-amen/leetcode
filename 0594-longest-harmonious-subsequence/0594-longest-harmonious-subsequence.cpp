class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int j = 0;
        int mx = 0;
        for(int i = 0; i < n; i++) {
            while(nums[i] - nums[j] > 1) {
                j++;
            }
            if(nums[i] - nums[j] == 1) {
                mx = max(mx,i-j+1);
            }
        }
        return mx;

        
    }
};