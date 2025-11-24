class Solution:
    def sortColors(self, nums: List[int]) -> None:
        i = 0
        j = len(nums)-1
        k = 0

        while k<=j:
            if nums[k] == 1:
                k = k + 1
            elif nums[k] == 2:
                nums[k],nums[j] = nums[j],nums[k]
                j = j -1
            
            else:
                nums[i],nums[k] = nums[k],nums[i]
                i = i + 1
                k = k + 1
                

        