class Solution {
private:
   bool f(string &s, int i, int j,vector<vector<int>>&dp) {
    
     if(i >= j)return true;
     if(s[i] == s[j]) {
        return f(s,i+1,j-1,dp);
     }
     return false;

   }
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        int sp = -1;
        int mx = -1;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
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