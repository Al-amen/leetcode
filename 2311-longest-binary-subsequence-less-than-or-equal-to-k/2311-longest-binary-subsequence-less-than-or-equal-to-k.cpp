class Solution {
public:
    int longestSubsequence(string s, int k) {

        reverse(s.begin(),s.end());
        int n = s.size();
        int cnt = 0;
        int p = 1;
        for(int i = 0 ; i < n; i++) {
            if(s[i] == '0') {
                cnt++;
            }
            else if( p <= k) {
                k -= p;
                cnt++;
            }
            if(p <= k) {
                p *= 2;
            }
        }
        return cnt;
        
    }
};