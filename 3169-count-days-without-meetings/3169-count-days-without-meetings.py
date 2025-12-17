from typing import List

class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        if not meetings:
            return days

        meetings.sort(key=lambda x: x[0])

        meeting_days = 0
        cur_start, cur_end = meetings[0]

        for i in range(1, len(meetings)):
            start, end = meetings[i]

            if start <= cur_end:          # overlap
                cur_end = max(cur_end, end)
            else:                         # no overlap
                meeting_days += (cur_end - cur_start + 1)
                cur_start, cur_end = start, end

        # add last interval
        meeting_days += (cur_end - cur_start + 1)

        return days - meeting_days
