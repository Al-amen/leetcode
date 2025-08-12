#include <vector>
using namespace std;
static const int MOD = 1'000'000'007;


class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<int>powers;
        for(int i = 1; ; i++) {
            long long p = 1;
            for(int k = 0; k < x; k++) p *= i;
            if(p > n)break;
            powers.push_back(p);
        }
        vector<long long > dp(n+1, 0);
        dp[0] = 1;

        for(int p: powers) {
            for(int s = n; s >= p; --s) {
                dp[s] = (dp[s] + dp[s-p]) % MOD;
            }
        }

        return dp[n];
        
    }
};