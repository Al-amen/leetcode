class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(s) < len(p):
            return []
        
        p_count = [0] * 26
        s_count = [0] * 26

        for char in p:
            p_count[ord(char) - ord('a')] += 1
        
        result = []
        for i in range(len(s)):
            s_count[ord(s[i]) - ord('a')] += 1

            if i >= len(p):
                s_count[ord(s[i - len(p)]) - ord('a')] -= 1
            
            if s_count == p_count:
                result.append(i-len(p) + 1)

        
        return result
        