class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        
        long long total = 0;
        long long sub_arry = 0;
        
        for( int i = 0; i < n; i++) {
            if(nums[i] == 0){
                sub_arry++;
                total += sub_arry;
            }
            else {
                sub_arry = 0;
            }
        }
        
        return total;
        
    }
};