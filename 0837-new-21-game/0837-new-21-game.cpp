class Solution {
public:
    double new21Game(int n, int k, int mx) {
        if(k == 0 || n >= k + mx)return 1.0;
        vector<double>dp(n+1);
        dp[0] = 1.0;
        double mxsum = 1.0, res = 0.0;
        for(int i = 1; i<= n; i++) {
            dp[i] = mxsum / mx;
            if(i < k)mxsum += dp[i];
            else res += dp[i];
            if(i - mx >= 0)mxsum -= dp[i-mx];
        }

        return res;
        
    }
};