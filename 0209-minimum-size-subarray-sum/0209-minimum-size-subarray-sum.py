class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:

        i : int = 0
        j : int = 0
        n : int = len(nums)
        window_sum : int = 0
        min_len : int = 1000000    # 2 3 1 2 4 3
                                     #  1+2+4+3


        while j < n:
            
            window_sum += nums[j]

            while window_sum >= target:
                min_len = min(min_len,j-i+1)
                window_sum -= nums[i]
                i += 1
            j += 1


        
        return 0 if min_len == 1000000 else min_len

        

            



        