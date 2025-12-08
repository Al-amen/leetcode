class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        from collections import defaultdict
        freq = defaultdict(int)
        max_len = 0
        max_freq = 0
        i = 0

        for j in range(len(s)):
            freq[s[j]] += 1
            max_freq = max(max_freq,freq[s[j]])
            if j - i + 1 - max_freq <= k:
                max_len = max(max_len,j-i+1)
            else:
                freq[s[i]] -= 1
                if freq[s[i]] == 0:
                    del freq[s[i]]
                freq[j] += 1
                    
                i += 1
            j += 1

        return max_len