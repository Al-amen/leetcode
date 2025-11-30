class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        from collections import defaultdict

        freq = defaultdict(int)

        window_sum = 0
        max_sum = 0
        left = 0
        n = len(nums)

        for right in range(n):
            freq[nums[right]] += 1
            window_sum += nums[right]

            # keep window size exactly k
            if right - left + 1 > k:
                freq[nums[left]] -= 1
                if freq[nums[left]] == 0:
                    del freq[nums[left]]
                window_sum -= nums[left]
                left += 1
            
            # when window size == k, check distinct
            if right - left + 1 == k:
                if len(freq) == k:
                    max_sum = max(max_sum, window_sum)
        
        return max_sum

        