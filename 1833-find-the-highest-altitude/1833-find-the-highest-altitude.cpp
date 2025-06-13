class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int x = 0;
        int h = x;

        for(auto it: gain) {
            x += it;
            h = max(h,x);
        }
        return h;
        
    }
};