class Solution {
public:
    bool is_vowel(char ch) {
        return (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U') ;
    }
    bool isValid(string word) {
        int n = word.size();
        if(n < 3) return false;
        int digit = 0;
        int uppercase = 0;
        int lowercase = 0;
        int vowel = 0;
        int consonant = 0;
        int others = 0;

        for(int i = 0; i < n; i++) {
            if(isdigit(word[i])) {
                digit++;
            }
            else if(isalpha(word[i])) {
                if(is_vowel(word[i])) {
                    vowel++;
                    if(isupper(word[i]))uppercase++;
                    else lowercase++;

                }
                else {
                    consonant++;
                    if(isupper(word[i]))uppercase++;
                    else lowercase++;
                }

            }
            else {
                others++;
            }
        }
        if(others)return false;

        if(consonant && vowel) {
            return digit + vowel + consonant >= 3;
        }
        return false;

    }
};