class Solution:
    def reverseWords(self, s: str) -> str:
        s.strip()
        x = s.split()

        for i in range(len(x)-1):
            if x[i] == x[i+1] == " ":
               x.pop(i)

        x.reverse()

        return " ".join(x)



        



        
       




        