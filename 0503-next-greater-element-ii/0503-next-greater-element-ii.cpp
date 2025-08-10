class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st; // stores values, not indices

        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i % n] = st.top();
            }
            st.push(nums[i % n]);
        }

        return ans;
    }
};
