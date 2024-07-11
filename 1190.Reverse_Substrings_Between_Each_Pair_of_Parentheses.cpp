class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
    stack<int> st;
    queue<char> q;
    string res;
    
    for (int i = 0; i < n; i++) {
       
        if(s[i] == '(') {
           // cout << x << " ";
           st.push(res.length());
        }
        else if(s[i] == ')' ) {
            int tp = st.top();
            st.pop();

            reverse(res.begin()+tp, res.end());
            cout << tp << " " << res << endl;
         }
        else  {

            res.push_back(s[i]);
        }
    }

        
       return res;
        
    }
};