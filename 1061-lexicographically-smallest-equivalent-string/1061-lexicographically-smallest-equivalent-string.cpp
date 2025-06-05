class Solution {
public:
    int find(vector<int>&dsu, int v) {
        if(dsu[v] == -1) {
            return v;
        }
        return dsu[v] = find(dsu,dsu[v]);
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int>dsu(26,-1);
        int n = s1.size();
        for(int i = 0; i < n; i++) {
            if(s1[i] == s2[i])continue;

            int px = find(dsu,s1[i]-'a');
            int py = find(dsu,s2[i]-'a');

            if(px == py)continue;
            if(px > py)dsu[px] = py;
            else dsu[py] = px;

        }
        string res;

        for(int i = 0; i < baseStr.size(); i++) {
            int parent = find(dsu,baseStr[i]-'a');
            res.push_back(char(97+parent));
        }
        return res;
    }
};