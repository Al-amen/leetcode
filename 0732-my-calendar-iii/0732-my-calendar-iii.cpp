class MyCalendarThree {
public:
    map<int,int>mp;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        mp[startTime] += 1;
        mp[endTime] -= 1;
        int cnt = 0;
        int mx = 0;
        for(auto &it : mp) {
            cnt += it.second;
            mx = max(cnt, mx);
        }
        return mx;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */