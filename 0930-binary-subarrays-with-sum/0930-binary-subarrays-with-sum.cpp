class Solution {

private:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0; 
        int n = nums.size();
        int l = 0, r = 0, sum = 0, totalSubarrays = 0;

        while (r < n) {
            sum += nums[r];
            while (sum > goal) {
                sum -= nums[l];
                l++;
            }
            totalSubarrays += (r - l + 1);
            r++;
        }
        return totalSubarrays;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};