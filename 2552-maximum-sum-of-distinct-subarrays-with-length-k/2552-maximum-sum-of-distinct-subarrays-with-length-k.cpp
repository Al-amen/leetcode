class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        long long sum = 0, max_sum = 0;
        unordered_map<int, int> mp;

        for (int j = 0; j < n; ++j) {
            sum += nums[j];
            mp[nums[j]]++;

            if (j - i + 1 > k) {
                mp[nums[i]]--;
                sum -= nums[i];
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }

            if (j - i + 1 == k && mp.size() == k) {
                max_sum = max(max_sum, sum);
            }
        }

        return max_sum;
    }
};
