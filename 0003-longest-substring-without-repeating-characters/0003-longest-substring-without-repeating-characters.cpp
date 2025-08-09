class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> mp; // faster than map
        int j = 0, max_len = 0;

        for (int i = 0; i < n; i++) {
            mp[s[i]]++;

            while (mp[s[i]] > 1) { // duplicate found
                mp[s[j]]--;
                if (mp[s[j]] == 0) {
                    mp.erase(s[j]);
                }
                j++;
            }
            max_len = max(max_len, i - j + 1);
        }

        return max_len;
    }
};
