class Solution {
public:
    bool judgeSquareSum(int c) {
        int l = 0; 
        int r = sqrt(c) + 1;

        while(l <= r) {
            long long x = l * l;
            x += (long long) r * r;
            if ((long long)l*l == c)return true;
            else if((long long)r*r == c)return true;
            if(x == c) {
                return true;
            }
            else if(x < c) {
                l++;
            }
            else r--;
        }
        return false;
        
    }
};