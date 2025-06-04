class Solution:
    def search(self, nums: List[int], target: int) -> int:

        left,right = 0, len(nums)-1

        while left<=right:
            
            mid = (left+right)//2
            if nums[mid] == target:
                return mid

            if nums[left] < nums[mid] and target >= nums[left] and target < nums[mid]:
                right = mid - 1
            
            elif nums[right] > nums[mid] and target > nums[mid] and target <= nums[right]:
                left = mid + 1
            
            elif nums[left] > nums[mid]:
                right = mid - 1
            
            else: 
                left = mid + 1
        
        return -1


        