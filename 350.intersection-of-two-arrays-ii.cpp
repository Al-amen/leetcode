/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
    bool binarySearch(vector<int>&nums2, int target) {
        int r = nums2.size()-1;
        int l = 0;
        while(l<=r) {
            int mid = (l + r) / 2;
            if(nums2[mid] == target){
                nums2.erase(nums2.begin()+mid);
                return true;
            }
            if(target>nums2[mid]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return false;
    }

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        
        sort(nums2.begin(), nums2.end());
        sort(nums1.begin(),nums1.end());
        vector<int> v;
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
           if(binarySearch(nums2, nums1[i])){
               v.push_back(nums1[i]);
               
           }
        }
        return v;
    }
};
// @lc code=end

