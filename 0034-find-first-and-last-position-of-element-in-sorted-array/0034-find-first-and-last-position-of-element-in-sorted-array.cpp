class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int x = -1;
        while(l<=r) {
            int mid = (l+r) / 2;
            if(target == nums[mid]) {
                x = mid;
                r = mid - 1;
            }
            else if(target > nums[mid]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }

            
            
        }
        return x;
    }
    int upper_bound(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int x = -1;
        while(l<=r) {
            int mid = (l+r) / 2;
            if(target == nums[mid]) {
                x = mid;
                l = mid+1;
            }
            else if(target > nums[mid]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }

            
            
        }
        return x;
    }
    vector<int> searchRange(vector<int>& nums, int target) {

        int x = lower_bound(nums,target);
        int y = upper_bound(nums,target);

        return (x == -1 ? vector<int>{-1, -1} : vector<int>{x, y});
        
    }
};