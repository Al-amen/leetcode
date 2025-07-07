import heapq
from typing import List

class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        events.sort(key=lambda x: x[0])  # Sort by start day
        pq = []  # Min-heap to store end days
        i = 0
        res = 0
        n = len(events)
        day = 1

        while i < n or pq:
            # Add all events starting today
            while i < n and events[i][0] == day:
                heapq.heappush(pq, events[i][1])
                i += 1

            # Remove all events that have already ended
            while pq and pq[0] < day:
                heapq.heappop(pq)

            
            if pq:
                heapq.heappop(pq)
                res += 1

            day += 1

        return res



        