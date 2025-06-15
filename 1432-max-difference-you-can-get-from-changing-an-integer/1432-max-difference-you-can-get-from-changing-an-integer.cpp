class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string t = s;

        // Replace a digit to make the number as big as possible
        size_t pos = s.find_first_not_of('9');
        if (pos != string::npos) {
            char to_replace = s[pos];
            replace(s.begin(), s.end(), to_replace, '9');
        }

        // Replace a digit to make the number as small as possible
        if (t[0] != '1') {
            char to_replace = t[0];
            replace(t.begin(), t.end(), to_replace, '1');
        } else {
            for (int i = 1; i < t.size(); i++) {
                if (t[i] != '0' && t[i] != '1') {
                    char to_replace = t[i];
                    replace(t.begin(), t.end(), to_replace, '0');
                    break;
                }
            }
        }

        return stoi(s) - stoi(t);
    }
};
