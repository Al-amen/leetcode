class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int l = 0; 
        int r = 0;
        int total_substring = 0;
        int abc[3] = {-1,-1,-1};

        for(int i = 0; i < n; i++) {
            abc[s[i]-'a'] = i;
            if(abc[0] != -1 && abc[1] != -1 && abc[2] != - 1) {
                total_substring += (1+ min(abc[0],min(abc[1],abc[2])));
            } 
        }
        return total_substring;
        
    }
};