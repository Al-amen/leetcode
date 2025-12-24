class MyCalendarTwo {
    map<int,int>bkCount;
    int maxOverlappedBooking;
public:
    MyCalendarTwo() {
        maxOverlappedBooking = 2;
    }
    
    bool book(int start, int end) {
        bkCount[start]++;
        bkCount[end]--;

        int overlappedBooking = 0;
        for (pair<int,int>bookings: bkCount){
            overlappedBooking += bookings.second;

            if (overlappedBooking > maxOverlappedBooking) {
                bkCount[start]--;
                bkCount[end]++;

                if(bkCount[start] == 0) {
                    bkCount.erase(start);
                }
                if(bkCount[end] == 0) {
                    bkCount.erase(end);
                }

                return false;


            }
            
        }
        return true;

    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */