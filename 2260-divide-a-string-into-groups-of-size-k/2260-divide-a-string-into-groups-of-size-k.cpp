class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        cout << n << endl;
        if(n % k != 0) {
            int remin = n %k;
            n += k-remin;

            for(int i = 0; i < k-remin; i++)s.push_back(fill);
        }

        vector<string> vs;
        cout << n << endl;
        for(int i = 0; i < n; i += k) {
            string a = s.substr(i,k);
            vs.push_back(a);
        }

        return vs;

        
    }
};