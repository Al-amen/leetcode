class Solution {
public:
    void merage(vector<int>& nums, int l, int mid, int r) {
        vector<int> temp;
        int left = l;
        int right = mid + 1;

        // Merge the two halves into temp
        while (left <= mid && right <= r) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        // Copy remaining elements from left half
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        // Copy remaining elements from right half
        while (right <= r) {
            temp.push_back(nums[right]);
            right++;
        }

        // Copy sorted elements back into original array
        for (int i = l; i <= r; ++i) {
            nums[i] = temp[i - l];
        }
    }

    void merage_sort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int mid = (l + r) / 2;
        merage_sort(nums, l, mid);
        merage_sort(nums, mid + 1, r);
        merage(nums, l, mid, r);
    }

    vector<int> sortArray(vector<int>& nums) {
        merage_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};
