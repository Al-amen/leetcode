class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        
        # 0 1 2 3 4
        # 1 3 4 2 2

        #                  ----
        #                 |    |
        # 0 -> 1 -> 3 -> 2 -> 4 

        n : int = len(nums)
        slow : int = 0
        fast : int = 0

        while True:

            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:
                break

        
        n1 = 0
        n2 = slow

        while n1 != n2:
            n1 = nums[n1]
            n2 = nums[n2]
        
        return n1





