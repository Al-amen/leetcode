class Solution {
public:
    int differenceOfSums(int n, int m) {
        long long x = 0;
        long long y = 0;
        for(int i = 1; i <= n; i++) {
            if(i%m)x += i;
            else y += i;
        }
        return x - y;
    }
};