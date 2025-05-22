class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> used_query;  // ending soonest
        priority_queue<int> available_query;  // ending latest first

        sort(queries.begin(), queries.end());
        int query_pos = 0;
        int applied_count = 0;

        for (int i = 0; i < n; i++) {
            // Push available queries starting at current index
            while (query_pos < queries.size() && queries[query_pos][0] == i) {
                available_query.push(queries[query_pos][1]);
                query_pos++;  // ✅ Important to increment
            }

            nums[i] -= used_query.size();  // Apply already used queries

            // Apply more queries if needed
            while (nums[i] > 0 && !available_query.empty() && available_query.top() >= i) {
                used_query.push(available_query.top());
                available_query.pop();
                nums[i]--;
                applied_count++;
            }

            if (nums[i] > 0) return -1;  // Cannot reduce this element to 0

            // Remove queries that expire at this index
            while (!used_query.empty() && used_query.top() == i) {
                used_query.pop();
            }
        }

        return queries.size() - applied_count;
    }
};
