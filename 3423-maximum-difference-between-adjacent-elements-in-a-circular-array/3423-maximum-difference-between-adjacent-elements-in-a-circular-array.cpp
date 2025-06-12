class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int diff = 0;
        int mx = 0;
        for(int i = 1; i < nums.size(); i++) {
            mx = max(mx,abs(nums[i]-nums[i-1]));

        }
        mx = max(mx,abs(nums[0]-nums[nums.size()-1]));

        return mx;
    }
};