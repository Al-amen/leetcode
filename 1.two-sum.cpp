/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */


// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

         vector<pair<int, int>> vs; // Vector of pairs to store number and its index
        vector<int> ind;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
           vs.push_back(make_pair(nums[i], i)); // Add pairs to the vector
        }
        
        sort(vs.begin(), vs.end()); // Sort the vector of pairs

        int l = 0, r = n - 1;
        
        while (l < r) {
            int sum = vs[l].first + vs[r].first;
            
            if (sum == target) {
                ind.push_back(vs[l].second);
                ind.push_back(vs[r].second);
                break; // Found the solution, break the loop
            } else if (sum > target) {
                r--; // Move the right pointer to the left
            } else {
                l++; // Move the left pointer to the right
            }
        }
        
        return ind; // Return the indices
    }
};
// @lc code=end

