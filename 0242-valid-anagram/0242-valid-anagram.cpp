class Solution {
public:
    bool isAnagram(string s, string t) {
        int len1 = s.size();
        int len2 = t.size();

        if(len1 != len2)return false;

        for(int i = 0; i < len1; i++) {
            if(count(s.begin(),s.end(),s[i]) != count(t.begin(),t.end(),s[i]))return false;
        }
        return true;
    }
};