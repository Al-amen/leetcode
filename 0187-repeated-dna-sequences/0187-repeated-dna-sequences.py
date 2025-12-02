class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        if len(s) < 10:
            return []

        # Map DNA chars to digits
        mp = {'A':0, 'C':1, 'G':2, 'T':3}

        B = 4               # base
        L = 10              # window length
        power = B**(L-1)    # B^9

        h = 0               # current rolling hash
        seen = set()        # hashes seen once
        repeated = set()    # hashes seen more than once

        # Build first window hash
        for i in range(L):
            h = h * B + mp[s[i]]

        seen.add(h)

        # Slide window
        for i in range(1, len(s)-L+1):
            left_char = mp[s[i-1]]
            right_char = mp[s[i+L-1]]

            # Rolling hash update
            h = (h - left_char * power) * B + right_char

            if h in seen:
                repeated.add(s[i:i+L])
            seen.add(h)

        return list(repeated)

        