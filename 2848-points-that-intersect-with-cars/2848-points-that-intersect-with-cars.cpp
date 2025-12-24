class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
    int line [102] ={};
    for(auto& p : nums){
        line[p[0]]++;
        line[p[1]+1]--;
    }
    int ans =0;
    int count =0;
    for(int i =0; i <102; ++i){
        count += line[i];
        if(count > 0){
            ++ans;
        }
    }
    return ans;
}
};