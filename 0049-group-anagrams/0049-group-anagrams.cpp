class Solution {
public:
    int base1 = 131, base2 = 151;
    int mod1 = 1e9 + 7, mod2 = 1e9 + 9;

    pair<int, int> get_freq_hash(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        int h1 = 0, h2 = 0;
        for (int i = 0; i < 26; ++i) {
            h1 = (1LL * h1 * base1 + freq[i]) % mod1;
            h2 = (1LL * h2 * base2 + freq[i]) % mod2;
        }
        return {h1, h2};
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<pair<int,int>, vector<string>> mp;

        for (string& str : strs) {
            pair<int,int> p = get_freq_hash(str);
            mp[p].push_back(str);
        }

        vector<vector<string>> res;
        for (auto& it : mp) {
            res.push_back(it.second);
        }

        return res;
    }
};
