class Solution:
    def getLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:

       n = len(groups)
       ans = []

       for i in range(0,n):
           if i == 0 or groups[i] != groups[i-1]:
              
               ans.append(words[i])

       return ans


              
               
          


        
                        




            

        