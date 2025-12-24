from collections import defaultdict
from typing import List

class Solution:
    def numberOfPoints(self, nums: List[List[int]]) -> int:
        diff = defaultdict(int)

        for s, e in nums:
            diff[s] += 1
            diff[e + 1] -= 1   # inclusive interval

        covered = 0
        active = 0
        prev = None

        for point, val in sorted(diff.items()):
            # count span since previous point, if covered
            if prev is not None and active > 0:
                covered += point - prev

            active += val
            prev = point

        return covered
