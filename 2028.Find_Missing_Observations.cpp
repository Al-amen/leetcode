class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sz = rolls.size();
        int N = n + sz;
        int total = accumulate(rolls.begin(), rolls.end(), 0);
        int x = mean*N - total;
        int a = x /n;
        int r = x%n;

        if(x > 6*n || x <n) {
            return {};
        }
        vector<int>v(n,a);
        for(int i = 0; i < r; i++) {
            v[i]++;
        }
        return v;


    }
};