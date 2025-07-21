class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
      
        int cnt = 1;
        string res;
        res += s[0];
        

        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) {
                cnt++;
                
            }
            else {
                cnt = 1;
                
            }
            if(cnt < 3) {
                //cout << cnt << endl;
                res += s[i];
            }
            
        }
        return res;
        
    }
};