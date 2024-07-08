
class Solution {
public:
    int findTheWinner(int n, int k) {
        int x = 0; 
        for(int i = 1; i<=n; i++) {
            x = (x+k)%i;

        }
        return x+1;
    }
};
