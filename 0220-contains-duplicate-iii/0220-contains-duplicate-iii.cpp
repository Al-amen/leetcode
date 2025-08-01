class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<int>window;
        for(int i = 0; i < nums.size(); i++) {
            if( i > indexDiff) window.erase(nums[i-indexDiff-1]);

            auto pos = window.lower_bound(nums[i]-valueDiff);

            if(pos != window.end() && *pos - nums[i] <= valueDiff) return true;
            window.insert(nums[i]);
        }
        return false;
    }
};