class Solution:
    def validPalindrome(self, s: str) -> bool:

        def check(i,j):
            while(i < j):
                if s[i] != s[j]:
                    return False
                i += 1
                j -= 1
            
            return True



        left = 0
        right = len(s) - 1
        n = right
        miss_match_pair = 0

        while(left < right):
            if s[left] != s[right]:
               return check(left+1,right) or check(left,right-1)
            
            right -= 1
            left += 1
        
        return True
        
       
        

            



        