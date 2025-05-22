class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto it: nums)mp[it]++;
        priority_queue<pair<int,int>>pq;
        for(auto it: mp) {
            pq.push({it.second,it.first});
        }
        vector<int>v;
        while(k--) {
            auto [x,y] = pq.top();
            v.push_back(y);
            pq.pop();

        }

        return v;
       
        
    }
};