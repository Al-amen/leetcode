from collections import defaultdict
from typing import List

class Solution:
    def maximumPopulation(self, logs: List[List[int]]) -> int:
        mp = defaultdict(int)

        # Difference map
        for birth, death in logs:
            mp[birth] += 1
            mp[death] -= 1

        max_p = 0
        count = 0
        ans_year = 0

        # Sweep sorted years
        for year, val in sorted(mp.items()):
            count += val

            if count > max_p:
                max_p = count
                ans_year = year

        return ans_year
