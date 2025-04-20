class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int total = 0;
        unordered_map<int,int> mp;
        for(int i : answers)mp[i]++;

        for(auto & x: mp) {
            total += ceil((double)x.second /(x.first+1)) * (x.first+1);
        }

        return total;


        
    }
};