class Solution {
public:
    char kthCharacter(int k) {
        string sb = "a";
        while(sb.size()<k) {
            int ln = sb.size();

            for(int i = 0; i < ln; i++) {
                char nextChar = 'a' + ((sb[i] - 'a' )+1) % 26;
                sb += nextChar;
            }
        }

        return sb[k-1];
        
    }
};