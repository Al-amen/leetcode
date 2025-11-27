class Solution:
    def digitSum(self, n: int) -> int:
        sum_sq: int = 0
        while n != 0:
            digit: int = n % 10
            n //= 10  # Use integer division
            sum_sq += (digit * digit)
        return sum_sq

    def isHappy(self, n: int) -> bool:
        slow: int = n
        fast: int = n

        while True:
            slow = self.digitSum(slow)
            fast = self.digitSum(self.digitSum(fast))

            if fast == 1:
                return True
            if fast == slow:
                return False