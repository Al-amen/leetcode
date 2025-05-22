class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        
        for(auto it: s)mp[it]++;
        priority_queue<pair<int,char>>pq;
        for(auto it: mp) {
            pq.push({it.second,it.first});
        }
        string ans;
        while(!pq.empty()) {
            auto [x,y] = pq.top();
            pq.pop();
            while(x--) {
                ans.push_back(y);
            }

        }
        return ans;

        
        
        
    }
};