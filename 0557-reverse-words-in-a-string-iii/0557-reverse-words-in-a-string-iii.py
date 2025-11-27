class Solution:
    def reverseWords(self, s: str) -> str:
        
        x = s.split()

        for i, val in  enumerate(x):
             l : int = 0
             r : int = len(val)
            
             
             x.pop(i)
             x.insert(i,val[::-1])
            
        
        print(x)

        return " ".join(x)

        