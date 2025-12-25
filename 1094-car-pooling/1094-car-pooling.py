from typing import List

class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        mp = {}

        # difference map
        for passengers, start, end in trips:
            mp[start] = mp.get(start, 0) + passengers
            mp[end]   = mp.get(end, 0)   - passengers

        curr = 0

        # sweep timeline
        for _, val in sorted(mp.items()):
            curr += val
            if curr > capacity:
                return False

        return True
