class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()  # Correct sorting
        ans = []     # Initialize ans as an empty list

        for i, val in enumerate(nums):  # Correct enumerate
            if val > 0:
                break
            if i == 0 or nums[i] != nums[i-1]:  # Correct duplicate check
                self.find_two_sum(i, nums, ans) # Call helper method on self

        return ans

    def find_two_sum(self, k, nums: List[int], ans: List[List[int]]) -> None: # Renamed and adjusted type hint
        left = k + 1  # Start left pointer after k
        right = len(nums) - 1

        while left < right:
            current_sum = nums[k] + nums[left] + nums[right]

            if current_sum < 0:
                left += 1
            elif current_sum > 0:
                right -= 1
            else:
                ans.append([nums[k], nums[left], nums[right]])
                left += 1
                right -= 1

                # Skip duplicates for left pointer
                while left < right and nums[left] == nums[left - 1]:
                    left += 1
                # Skip duplicates for right pointer
                while left < right and nums[right] == nums[right + 1]:
                    right -= 1