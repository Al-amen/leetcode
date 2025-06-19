class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int max_element = nums[0];
        int min_element = nums[0];
        int cnt = 1;

        for(int i = 1; i < n; i++) {
            if(nums[i]-min_element > k) {
                cnt++;
                min_element = max(min_element,nums[i]);
            }
        }
        return cnt;
        
    }
};