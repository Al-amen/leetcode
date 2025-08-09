class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        stack<char>st1,st2;

        for(int i = 0; i < s.size(); i++) {
            if(!st1.empty()) {
                if(s[i] == '#') {
                    st1.pop();
                }
                else {
                    st1.push(s[i]);
                }
            }
            else {
                if(s[i] != '#')
                  st1.push(s[i]);
            }
        }
        for(int i = 0; i < t.size(); i++) {
            if(!st2.empty()) {
                if(t[i] == '#') {
                    st2.pop();
                }
                else {
                    st2.push(t[i]);
                }
            }
            else {
                if(t[i] != '#')
                   st2.push(t[i]);
            }
        }
        
        string res1 = "";
        string res2 = "";

        while(!st1.empty()) {
            res1 += st1.top();
            st1.pop();
        }

        while(!st2.empty()) {
            res2 += st2.top();
            st2.pop();
        }

        cout << res1 << " " << res2;

        return res1 == res2;
    }
};