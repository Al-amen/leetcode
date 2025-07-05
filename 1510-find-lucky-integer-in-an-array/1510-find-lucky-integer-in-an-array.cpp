class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int>mp;
        for(int x: arr) {
            mp[x]++;
        }
        int max_lucky = -1;
        for(auto it: mp) {
            if(it.first == it.second) {
                max_lucky = max(max_lucky,it.first);
            }
        }
        return max_lucky;
        
    }
};