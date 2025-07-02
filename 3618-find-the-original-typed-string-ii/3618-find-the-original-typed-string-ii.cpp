class Solution {
public:
    int possibleStringCount(string word, int k) {
        int n = word.size();
        int cnt = 1;
        int mod = 1e9 + 7;
        vector<int>grp;
        for(int i = 0 ;i < n-1; i++) {
            if(word[i] == word[i+1]) {
                
                cnt++;
                
            }
            else {
                grp.push_back(cnt);
                cnt = 1;
            }
        }
        grp.push_back(cnt);

        long long total = 1;
        for(int num: grp){
            total = (total * num) % mod;
        }
        int sz = grp.size();
        if(k <= sz ) return total;
        vector<int>dp(k,0);
        dp[0] = 1;

        for(int num: grp) {
            vector<int>newDp(k,0);
            long long sum = 0;
            for(int s = 0; s < k; s++) {
                if (s > 0)sum = (sum + dp[s-1]) % mod;
                if(s > num) sum = (sum - dp[s-num-1] + mod) % mod;
                newDp[s] = sum;
            }
            dp = newDp;
        }

        long long invalid = 0;
        for(int s = sz; s < k; s++) {
            invalid = (invalid + dp[s]) % mod;
        }

        return (total - invalid + mod) % mod;
        
    }
};