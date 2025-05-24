class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>v;
        for(int i = 0; i < words.size(); i++) {
            if(words[i].find(x) != string::npos) {
                v.push_back(i);
            }
        }
        return v;
        
    }
};