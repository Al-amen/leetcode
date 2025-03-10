class Solution {
private:
int maxSum(vector<int>&nums) {
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;

    for(int i = 1; i < n; i++) {
        int take = nums[i];
        if(i > 1){
            take += prev2;
        }
        int notTake = 0 + prev;

        int current = max(take,notTake);
        prev2 = prev;
        prev = current;
    }

    return prev;

}

public:
    int rob(vector<int>& nums) {
        vector<int>temp1,temp2;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(i != 0)temp1.push_back(nums[i]);
            if(i != n-1)temp2.push_back(nums[i]);
        }
        if(n == 1)return nums[0];
        return max(maxSum(temp1),maxSum(temp2));
        
    }
};