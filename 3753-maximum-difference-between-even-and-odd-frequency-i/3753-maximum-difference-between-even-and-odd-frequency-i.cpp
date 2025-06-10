class Solution {
public:
    int maxDifference(string s) {
        map<char,int>mp;
        for(auto c : s)mp[c]++;

        int max_odd = 1; 
        int min_even = s.size();

        for(auto it: mp) {
            if(it.second%2) {
                max_odd = max(max_odd, it.second);
            }
            else {
                min_even = min(min_even,it.second);
            }
        }
        return max_odd - min_even;
        
    }
};