class Solution {
public:
    // Helper function to recursively solve the chemical formula
    int solve(int i, string s, int n, map<string, int>& prev_map) {
        map<string, int> t;
        
        // Iterate through the formula string
        for (; i < n; i++) {
            if (s[i] == '(') {
                // If an opening parenthesis is found, solve the nested formula
                i = solve(i + 1, s, n, t);
            } else if (isupper(s[i])) {
                // If an uppercase letter is found, it indicates the start of an element
                string temp;
                temp += s[i];
                i++;
                
                // Check for a lowercase letter indicating the full element symbol
                if (i < n && islower(s[i])) {
                    temp += s[i];
                    i++;
                }
                
                // Parse the element count if it exists
                int count = 0, j;
                for (j = i; j < n; j++) {
                    if (isdigit(s[j])) {
                        count = count * 10 + (s[j] - '0');
                    } else {
                        break;
                    }
                }
                
                // Update the element count in the current map
                t[temp] += (count == 0) ? 1 : count;
                i = (count == 0) ? i - 1 : j - 1;
            } else if (s[i] == ')') {
                // If a closing parenthesis is found, process the nested formula
                i++;
                int count = 0, j = i;
                
                // Parse the multiplier after the closing parenthesis
                if (i < n && isdigit(s[i])) {
                    for (j = i; j < n; j++) {
                        if (isdigit(s[j])) {
                            count = count * 10 + (s[j] - '0');
                        } else {
                            break;
                        }
                    }
                }
                
                // Apply the multiplier to the current map
                if (count) {
                    for (auto& it : t) {
                        it.second *= count;
                    }
                    i = j - 1;
                }
                
                // Merge the current map into the previous map
                for (auto& it : t) {
                    prev_map[it.first] += it.second;
                }
                return i - 1;
            }
        }
        
        // Merge the final map into the previous map
        for (auto& it : t) {
            prev_map[it.first] += it.second;
        }
        return i;
    }

    string countOfAtoms(string formula) {
        int n = formula.size();
        map<string, int> m;
        
        // Solve the formula and build the element count map
        solve(0, formula, n, m);
        
        // Build the result string from the element count map
        string res;
        for (auto& it : m) {
            res += it.first;
            if (it.second != 1) {
                res += to_string(it.second);
            }
        }
        return res;
    }
};