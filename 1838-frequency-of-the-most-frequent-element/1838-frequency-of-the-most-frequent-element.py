class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:

        # Step 1: Sort the numbers because we only increase values
        nums.sort()

        l = 0                      # left pointer of sliding window
        window_sum = 0             # sum of current window
        max_freq = 1               # maximum frequency found

        # Step 2: Expand the window with right pointer r
        for r in range(len(nums)):
            window_sum += nums[r]   # add the new element to the window sum

            # window size = (r - l + 1)
            # target value = nums[r] (rightmost value)

            # cost to make all values in the window equal to nums[r]
            # cost = window_size * nums[r] - sum(window)
            while (r - l + 1) * nums[r] - window_sum > k:
                # cost is too large, so shrink window from the left
                window_sum -= nums[l]
                l += 1

            # window is valid; update answer
            max_freq = max(max_freq, r - l + 1)

        return max_freq
