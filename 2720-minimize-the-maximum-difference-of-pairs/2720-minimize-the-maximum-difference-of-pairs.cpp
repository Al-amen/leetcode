class Solution {
public:
    bool canFormPairs(vector<int> & nums, int maxDiff, int p) {
        int i = 0, n = nums.size(), count = 0;
        while (i < n - 1) {
            if (nums[i + 1] - nums[i] <= maxDiff) {
                count++;
                i += 2; 
            } else {
                i++;
            }
        }
        return count >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int left = 0, right = nums.back() - nums.front();
        int ans = right;

        while(left <= right) {
            int mid = left + (right-left)/2;
            if (canFormPairs(nums, mid, p)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

     return ans;
        
    }
};