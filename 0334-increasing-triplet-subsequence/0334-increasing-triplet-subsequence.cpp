class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX;
        int b = INT_MAX;

        for(int n: nums) {
            if(n <= a)a = n;
            else if(n <= b) b = n;
            else return true;
        }
        return false;
        
    }
};