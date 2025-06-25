class Solution {
public:
    // Helper to count how many products nums1[i] * nums2[j] ≤ target
    int countForOneValue(const vector<int>& nums2, long long x1, long long target) {
        int left = 0, right = nums2.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            
            if ((x1 >= 0 && nums2[mid] * x1 <= target) ||
                (x1 < 0 && nums2[mid] * x1 > target)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        
        return x1 >= 0 ? left : nums2.size() - left;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long low = -1e10, high = 1e10;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            long long count = 0;
            for (int i = 0; i < nums1.size(); ++i) {
                count += countForOneValue(nums2, nums1[i], mid);
            }

            if (count < k) {
                low = mid + 1; // we need more products → move right
            } else {
                high = mid - 1; // mid could be our answer → move left
            }
        }

        return low;
    }
};
