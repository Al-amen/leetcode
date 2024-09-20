class Solution {
public:
    string shortestPalindrome(string s) {
        int length = s.size();
        if(length == 0) {
            return s;
        }

        int l = 0;
        for(int r = length - 1; r >= 0; r--) {
            if(s[l] == s[r]) {
                l++;
            }
        }
        if(l == length) {
            return s;
        }

        string nopalSuffix = s.substr(l);
        string revSuffix = string(nopalSuffix.rbegin(),nopalSuffix.rend());


        return revSuffix + shortestPalindrome(s.substr(0,l)) + nopalSuffix;
        
        
    }
};