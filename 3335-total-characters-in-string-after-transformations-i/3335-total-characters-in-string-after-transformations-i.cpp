class Solution {
public:
    int mod = 1e9 + 7;

    int lengthAfterTransformations(string s, int t) {
        int ans = 0;
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }
        for (int i = 0; i < t; i++) {
            vector<int> temp(26, 0);
            for (int j = 0; j < 25; j++) {
                temp[j + 1] = (temp[j + 1] + freq[j]) % mod;
            }
            temp[0] = (temp[0] + freq[25]) % mod;
            temp[1] = (temp[1] + freq[25]) % mod;

            freq = temp; 
        }

        // Sum the frequencies for the final answer
        for (int count : freq) {
            ans = (ans + count) % mod;
        }

        return ans;
    }
};
