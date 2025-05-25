class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i; j <n; j++) {
                if(nums[i] == 0 && nums[j] != 0) {
                    swap(nums[i],nums[j]);
                    
                }
            }
        }
        
    }
};