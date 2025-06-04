class Solution:
    def answerString(self, word: str, numFriends: int) -> str:
        if numFriends == 1:
            return word
        ans = ""
        n = len(word)
        for i in range(n):
            ans =  max(ans, word[i : min(i + n - numFriends + 1, n)])
        
        return ans

        