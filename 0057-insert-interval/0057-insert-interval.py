from typing import List

class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        intervals.sort(key=lambda x: x[0])
        ans = []
        inserted = False

        for interval in intervals:
            # interval completely before newInterval
            if interval[1] < newInterval[0]:
                ans.append(interval)

            # interval completely after newInterval
            elif interval[0] > newInterval[1]:
                if not inserted:
                    ans.append(newInterval)
                    inserted = True
                ans.append(interval)

            # overlapping case
            else:
                newInterval[0] = min(newInterval[0], interval[0])
                newInterval[1] = max(newInterval[1], interval[1])

        # if newInterval goes at the end
        if not inserted:
            ans.append(newInterval)

        return ans
