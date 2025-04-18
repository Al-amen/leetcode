#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int f(int ind1, int ind2, string &s, string &t, vector<vector<int>> &dp){
             if (ind1 < 0 || ind2 < 0)return 0;
             if(dp[ind1][ind2] != -1)return dp[ind1][ind2];
             if(s[ind1] == t[ind2]) {
                return dp[ind1][ind2] = 1 + f(ind1-1, ind2-1, s, t,dp);
             }
             else {
                return dp[ind1][ind2] =  max(f(ind1-1, ind2, s, t,dp), f(ind1,ind2-1,s,t,dp));
             }
        
        }

    public:
        int longestPalindromeSubseq(string s) {
            string t = s;
            reverse(t.begin(),t.end());
            int n = s.size();
            int m = t.size();
            vector<vector<int>>dp(n+1, vector<int>(m+1,-1));

            return f(n-1,m-1,s,t,dp);
            
        }
    };