class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int>mp;
        for(auto &it: trips){
            mp[it[1]] += it[0];
            mp[it[2]] -= it[0];
        }

        int count = 0;
        for(auto &it : mp) {
            count += it.second;
            if(count > capacity) {
                return false;
            }
        }
        return true;
    }
};