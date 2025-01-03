class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>has(256,-1);
        int l = 0, r = 0;
        int max_len = 0;
        int n = s.size();

        while(r < n) {
            if(has[s[r]] != -1) {
                if(has[s[r]] >= l) {
                    l = has[s[r]] + 1;
                }
            }
            has[s[r]] = r;
            max_len = max(max_len,r-l+1);
            r++;
        }

        return max_len;
    }
};