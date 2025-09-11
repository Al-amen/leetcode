class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        vector<char>v(n,'1');
        vector<char>vowel={'a','A','e','E','i','I','o','O','u','U'};
        vector<char>temp;
        for(int i = 0; i < n; i++) {
            auto it = find(vowel.begin(), vowel.end(), s[i]);
            if(it != vowel.end()) {
                temp.push_back(s[i]);
            }
            else {
                v[i] = s[i];
            }

        }

        sort(temp.begin(),temp.end());
        //for(int i = 0; i < temp.size(); i++)cout<<temp[i]<< " ";
        int j = 0;
        for(int i = 0; i < n; i++) {
            if(v[i] == '1') {
                v[i] = temp[j++];
               // cout << v[i] << " ";
            }
        }
        string st;
        for(int i = 0; i < n; i++) {
           st.push_back(v[i]);
        }

       // cout << st;
        return st;

        
    }
};