class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = 0;
        for(auto it: s) {
            if(it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u') {
                cnt++;
            }
        }
        if(cnt % 2 == 1 or (cnt > 0 && cnt%2 == 0))return true;
        else return false;

    }
   
};