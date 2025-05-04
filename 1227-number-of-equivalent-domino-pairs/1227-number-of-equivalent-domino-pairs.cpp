class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int cnt = 0;
        map<pair<int,int>,int> mp;
        for(int i = 0; i < dominoes.size(); i++) {
            sort(dominoes[i].begin(),dominoes[i].end());
            pair<int,int>p = {dominoes[i][0],dominoes[i][1]};
            mp[p]++;
            
        }
        for(auto it: mp) {
            cnt += (it.second * (it.second-1))/2;
        }

        return cnt;
        
    }
};