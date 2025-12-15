class Solution:
    def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:

        i : int = 0
        j : int = 0
        ans: List[List[int]] = []
        while i < len(firstList) and j < len(secondList):
            s1 : int = firstList[i][0]
            s2 : int = secondList[j][0]
            e1 : int = firstList[i][1]
            e2 : int = secondList[j][1]
            res = []
            if e1 >= s2 and e2 >= s1:
                ans.append([max(s1,s2),min(e1,e2)]) 
            if e1 <= e2:
                i += 1
            else:
                j += 1
            
        return ans

            


            
        