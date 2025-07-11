class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }

    bool is_overlap(vector<int>& a, vector<int>& b) {
        return !(a[1] < b[0] || b[1] < a[0]);
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> ans;

        bool inserted = false;
        for (int i = 0; i < n; i++) {
            if (intervals[i][1] < newInterval[0]) {
                ans.push_back(intervals[i]);  // No overlap, before newInterval
            }
            else if (intervals[i][0] > newInterval[1]) {
                if (!inserted) {
                    ans.push_back(newInterval);  // Insert before the rest
                    inserted = true;
                }
                ans.push_back(intervals[i]);  // After newInterval
            }
            else {
                // Overlapping, merge
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }

        if (!inserted) {
            ans.push_back(newInterval);  // Insert at the end if not already
        }

        return ans;
    }
};
