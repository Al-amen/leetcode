class Solution {
public:
    int possibleStringCount(string word) {
       
       int n = word.size();
        int cnt = 1;
        int ans = 0;
       for(int i = 0; i < n-1; i++) {
         if(word[i] == word[i+1]) {
            cnt++;
         }
         else {
            ans += cnt - 1;
            cnt = 1;
         }
       }
       if(cnt > 1) {
         ans += cnt - 1;
       }
       cout << ans << endl;
       return ans+1;
        
    }
};