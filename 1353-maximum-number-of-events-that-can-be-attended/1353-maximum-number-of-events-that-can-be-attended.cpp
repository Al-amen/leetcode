class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n = events.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        int day = 0, index = 0, ans = 0;

        while(!pq.empty() || index < n) {
            if(pq.empty()) {
                day = events[index][0];
            }

            while(index < n && events[index][0] <= day) {
                pq.push(events[index][1]);
                index++;

            }
            pq.pop();
            ans++;
            day++;

            while(!pq.empty() && pq.top() < day) {
                pq.pop();
            }
            
        }
        return ans;

        
        
    }
};