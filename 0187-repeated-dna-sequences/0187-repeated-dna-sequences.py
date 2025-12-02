class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        from collections import defaultdict

        freq = defaultdict(int)
        ans = set()

        for i in range(len(s)-9):
            print(f"{s[i:i+10]} -> {freq[s[i:i+10]]}")
            if freq[s[i:i+10]] > 0:
                ans.add(s[i:i+10])
            freq[s[i:i+10]] += 1

        return list(ans)
            


        