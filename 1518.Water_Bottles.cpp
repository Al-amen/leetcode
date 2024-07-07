class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        long long ans = numBottles;

        while(numBottles>=numExchange) {
            long long  x = numBottles / numExchange;
            long long r =  numBottles % numExchange;

            ans += x;
            numBottles = x + r;

        }
        return ans;
        
    }
};