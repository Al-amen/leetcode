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

        unordered_map<int, int> mp;
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> v;
        for (int i = 0; i < n1; i++) {
            mp[nums1[i]]++;
        }
        for (int i = 0; i < n2; i++) {
            if(mp[nums2[i]]>0){
                v.push_back(nums2[i]);
                mp[nums2[i]]--;
            }
        }

            return v;
    }
};
// @lc code=end

