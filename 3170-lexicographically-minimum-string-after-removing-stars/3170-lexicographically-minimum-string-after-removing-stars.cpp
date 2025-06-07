class Solution {
public:
    string clearStars(string s) {
        vector<vector<int>>pos(26);
        priority_queue<char,vector<char>,greater<char>>pq;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '*') {
                char c = pq.top();
                s[pos[c-'a'].back()] = '*';
                pos[c-'a'].pop_back();
                if(pos[c-'a'].empty()){
                    pq.pop();
                }
            }
            else{
                if(pos[s[i]-'a'].empty())pq.push(s[i]);
                pos[s[i]-'a'].push_back(i);
            }
        }
        string res;
        for(auto c : s){
            if(c >= 'a')res += c;
        }
        return res;
        
    }
};