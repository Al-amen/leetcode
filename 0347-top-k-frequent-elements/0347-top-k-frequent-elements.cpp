class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto it: nums) {
            mp[it]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it: mp) {
            pq.push({it.second,it.first});
        }
        vector<int>v;
        while(k--) {
            auto[i,j] = pq.top();
            pq.pop();
            v.push_back(j);
        }

        return v;
        
    }
};