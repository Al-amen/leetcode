class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        priority_queue<pair<long long ,int>,vector<pair<long long, int>>,greater<pair<long long,int>>> free_rooms, occupied_rooms;
        vector<int> freq(n,0);

        //Initially all rooms are free
        for(int i=0;i<n;++i)
            free_rooms.push({0,i});//{time,room_no} pair

        //Simulate Job Scheduling
        for(int i=0;i<meetings.size();++i){
            //Add rooms getting free now
            while(!occupied_rooms.empty() and occupied_rooms.top().first<=meetings[i][0]){
                pair<long long,int> curr = occupied_rooms.top();
                occupied_rooms.pop();
                curr.first = 0;
                free_rooms.push(curr);
            }
            //Assign a room to current meeting
            if(!free_rooms.empty()){
                pair<long long,int>  curr = free_rooms.top();
                free_rooms.pop();
                freq[curr.second]++;
                curr.first = meetings[i][1];
                occupied_rooms.push(curr);
            }else{
                pair<long long,int>  curr = occupied_rooms.top();
                occupied_rooms.pop();
                freq[curr.second]++;
                curr.first += 1LL*(meetings[i][1] - meetings[i][0]);
                occupied_rooms.push(curr);
            }
        }
        int max_meeting_room;
        int max_meetings = 0;
        for(int i=0;i<n;++i){
            if(freq[i]>max_meetings){
                max_meeting_room = i;
                max_meetings = freq[i];
            }
        }
        return max_meeting_room;
        
    }
};