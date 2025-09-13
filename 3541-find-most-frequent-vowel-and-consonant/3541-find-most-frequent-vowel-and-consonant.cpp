class Solution {
public:
    int maxFreqSum(string s) {
        map<char,int>vf,cf;
        int mx_vf = 0, mx_cf = 0;
        for(auto it : s) {
            if(it == 'a' | it == 'e' | it == 'i' | it == 'o' | it == 'u') {
                vf[it]++;
                mx_vf = max(mx_vf,vf[it]);
            }
            else {
                cf[it]++;
                mx_cf = max(mx_cf,cf[it]);
            }
        }

        return mx_cf + mx_vf;
    }
};