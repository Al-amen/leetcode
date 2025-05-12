class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        map<int,int>mp;
        vector<int>v;
        for(auto it: digits)mp[it]++;

        for(int i = 100; i < 1000; i++) {
            map<int,int>f;
            if(i%2==0) {
                int a = i%10;
                f[a]++;
                int b = (i/10)%10;
                f[b]++;

                int c = (i/100)%10;
                f[c]++;
                if(mp[a] >= f[a] && mp[b] >= f[b] && mp[c] >= f[c]) {
                    v.push_back(i);
                }

            }
            
        }
        sort(v.begin(),v.end());

        return v;
    }
};