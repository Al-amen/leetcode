class Solution {
public:
    string robotWithString(string s) {
        unordered_map<char,int>cnt;
        for(char c : s) {
            cnt[c]++;
        }
        stack<char>st;
        string res;

        char minChar = 'a';

        for(char c : s) {
            st.push(c);
            cnt[c]--;
            while(minChar != 'z' && cnt[minChar] == 0){
                minChar++;
            }
            while(!st.empty() && st.top() <= minChar) {
                res.push_back(st.top());
                st.pop();
            }
        }
        return res;
    }
};