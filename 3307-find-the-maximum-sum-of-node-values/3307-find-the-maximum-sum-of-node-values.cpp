class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0, cnt = 0, node_left = INT_MAX;
        for (long long n : nums) {
            sum += max(n ^ k, n);
            cnt += (n ^ k) > n;
            node_left = min(node_left, abs(n - (n ^ k)));
        }
        return sum - (cnt % 2 ? node_left : 0);
        
    }
};