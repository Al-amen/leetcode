from collections import defaultdict

class MyCalendarTwo:
    def __init__(self):
        self.bkCount = defaultdict(int)
        self.maxOverlappedBooking = 2

    def book(self, start: int, end: int) -> bool:
        # Apply booking tentatively
        self.bkCount[start] += 1
        self.bkCount[end] -= 1

        overlapped = 0
        
        # Sweep through time points in sorted order
        for t in sorted(self.bkCount):
            overlapped += self.bkCount[t]
            
            # Triple booking detected → rollback & reject
            if overlapped > self.maxOverlappedBooking:
                self.bkCount[start] -= 1
                self.bkCount[end] += 1

                # cleanup zero entries
                if self.bkCount[start] == 0:
                    del self.bkCount[start]
                if self.bkCount[end] == 0:
                    del self.bkCount[end]

                return False
        
        return True
