class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        int posCnt = 0;
        int posSum = 0;
        unordered_set<int>pos;
        for(int i = 0; i < n; i++) {
            if(nums[i]>0) {
                posCnt++;
                pos.insert(nums[i]);
            }
        }
        if(posCnt == 0) {
            return *max_element(nums.begin(),nums.end());

        }
        return accumulate(pos.begin(),pos.end(),0);
    }
};