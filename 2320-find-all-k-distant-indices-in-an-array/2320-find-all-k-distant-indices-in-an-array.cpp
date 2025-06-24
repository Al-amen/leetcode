class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        set<int> s;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == key) {
                int start = max(0, i - k);
                int end = min(n - 1, i + k);
                for (int j = start; j <= end; ++j) {
                    s.insert(j);
                }
            }
        }

        // Convert set to vector
        vector<int> result(s.begin(), s.end());
        return result;
    }
};
