class Solution {
public:
  string helper(string &t) {
    int cnt = 1;
    string s = "";
    for(int i = 1; i<t.size(); i++) {
        if(t[i] == t[i-1]){
            cnt++;
        }
        else {
            s += to_string(cnt) + t[i-1];
            cnt = 1;
        }
    }
     s += to_string(cnt) + t.back();
    return s;
  }
 
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 1; i <n; i++) {
            ans = helper(ans);
        }
        return ans;
    }
};