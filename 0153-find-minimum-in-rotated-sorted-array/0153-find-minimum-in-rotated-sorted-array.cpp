class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;

        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if(nums[lo] <= nums[hi]) {
                return nums[lo];
            }
            if(mid - 1 >= 0 && nums[mid] < nums[mid-1]) {
                return nums[mid];
            }
            if(mid + 1 < n && nums[mid+1] < nums[mid]) {
                return nums[mid+1];
            }
            if(nums[lo]<nums[mid]) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return -1;
        
    }
};