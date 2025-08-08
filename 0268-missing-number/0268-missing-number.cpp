class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, h = n - 1;
        int ans = n; // default to n if all numbers match

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (nums[mid] == mid) {
                l = mid + 1;
            } else {
                ans = mid;
                h = mid - 1;
            }
        }

        return ans;
    }
};
