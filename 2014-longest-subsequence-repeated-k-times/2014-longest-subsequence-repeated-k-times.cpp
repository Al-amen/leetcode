class Solution {
public:
    bool ifisexist(string& s, string& temp, int k) {
        string str = "";
        while(k--)str += temp;
        int j = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == str[j]) {
                j++;
            }
            if(j==str.size()) break;

        }
        return j == str.size();
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.size();
        queue<string>q;
        q.push("");
        string ans;

        while(!q.empty()) {
            string str = q.front();
            q.pop();

            for(char c = 'a'; c <= 'z'; c++) {
                string temp = str + c;
                if(ifisexist(s,temp,k)) {
                    q.push(temp);
                    if(temp.size() > ans.size() || temp > ans) {
                        ans = temp;
                    }
                }
            }
        }
        return ans;
        
    }
};