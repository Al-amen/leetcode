from typing import List

class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        if not meetings:
            return days

        # 1. Sort meetings by start day
        meetings.sort(key=lambda x: x[0])

        # 2. Merge intervals
        merged = []
        merged.append(meetings[0])

        for i in range(1, len(meetings)):
            if meetings[i][0] <= merged[-1][1]:
                merged[-1][1] = max(merged[-1][1], meetings[i][1])
            else:
                merged.append(meetings[i])

        # 3. Count total meeting days
        meeting_days = 0
        for start, end in merged:
            meeting_days += (end - start + 1)

        # 4. Free days
        return days - meeting_days
