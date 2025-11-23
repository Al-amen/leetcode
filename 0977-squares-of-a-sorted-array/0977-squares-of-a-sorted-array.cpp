class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i = 0;             // Left pointer
        int j = n - 1;         // Right pointer
        int k = n - 1;         // Position pointer for result array
        
        
        vector<int> ans(n);


        while(i <= j) {
      
            if(abs(nums[i]) > abs(nums[j])) {
                ans[k] = nums[i] * nums[i];
                i++;
            } else {
                ans[k] = nums[j] * nums[j];
                j--;
            }
            k--;
        }
        return ans;
    }
};