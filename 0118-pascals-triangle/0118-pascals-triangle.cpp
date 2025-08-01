class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
       
        ans.push_back({1});

        for(int i = 2; i <= numRows; i++) {
            vector<int>v;
            v.push_back(1);
            vector<int> temp = ans.back();
            for(int i = 1; i < temp.size(); i++) {
                v.push_back(temp[i] + temp[i-1]);
            }
            v.push_back(1);
            ans.push_back(v);
        }
        return ans;
        
    }
};