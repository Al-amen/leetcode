class Solution {
public:
    int commonPrefix(string a, string b) {
        int ind  = 0;
        int len = min(a.size(),b.size());

        while(ind < len && a[ind] == b[ind])ind++;

        return ind;

    }
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        string res = strs[0];

        for(int i = 1; i < n; i++) {
            int len = commonPrefix(strs[i],res);
            res = res.substr(0,len);
        }
        return res;
        

    }
};