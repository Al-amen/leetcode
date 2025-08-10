class Solution {
public:
    string get_sortedStr(int n) {
        string s = to_string(n);
        sort(s.begin(),s.end());

        return s;
    }
    bool reorderedPowerOf2(int n) {
        
        string s = get_sortedStr(n);

        for(int p = 0; p< 30; p++) {
            if(s == get_sortedStr( 1 << p)) {
                return true;
            }
        }
        return false;

    }
};