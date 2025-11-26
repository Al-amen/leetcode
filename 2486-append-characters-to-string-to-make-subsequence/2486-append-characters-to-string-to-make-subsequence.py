class Solution:
    def appendCharacters(self, s: str, t: str) -> int:

        i : int = 0
        j : int  = 0

        while i < len(s) and j < len(t):
            if s[i] == t[j]:
                i = i + 1
                j = j + 1
            else:
                i = i + 1
        
        return len(t) - j

        