class Solution {
private:
   bool f(string &s, int i, int j,vector<vector<bool>>&dp) {
    
     if(i >= j)return true;
     if(dp[i][j] != 0)return dp[i][j];
     if(s[i] == s[j]) {
        return dp[i][j] = f(s,i+1,j-1,dp);
     }
     return dp[i][j] = 0;

   }
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        int sp = -1;
        int mx = -1;
        vector<vector<bool>>dp(n+1,vector<bool>(n+1,0));
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(f(s,i,j,dp)) {
                    int len = j-i+1;

                    if(mx < len) {
                        sp = i;
                        mx = max(len,mx);
                    }
                }
            }
        }

        return s.substr(sp,mx);
    }
};