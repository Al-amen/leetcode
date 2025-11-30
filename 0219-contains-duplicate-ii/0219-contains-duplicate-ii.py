class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        window = set()
        left = 0

        for right in range(len(nums)):
            # If nums[right] is already in window → duplicate found
            if nums[right] in window:
                return True

            window.add(nums[right])

            # keep window size <= k
            if right - left == k:
                window.remove(nums[left])
                left += 1

        return False
