class Solution {

private:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0; 
        int n = nums.size();
        int l = 0, r = 0, sum = 0, totalSubarrays = 0;

        while (r < n) {
            sum += (nums[r]%2);
            while (sum > goal) {
                sum -= (nums[l]%2);
                l++;
            }
            totalSubarrays += (r - l + 1);
            r++;
        }
        return totalSubarrays;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};