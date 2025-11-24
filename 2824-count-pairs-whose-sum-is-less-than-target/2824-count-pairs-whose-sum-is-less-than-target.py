class Solution:
    def countPairs(self, nums: List[int], target: int) -> int:
        n = len(nums)
        i = 0
        j = n-1
        nums.sort()
        count = 0

        while i < j:
            if nums[i] + nums[j] < target:
                count = count + (j-i)
                i = i + 1
            else:
                j = j - 1
        
        return count
            
        