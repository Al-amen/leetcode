class Solution {
public:
 void findCombination(int ind,int n, int target,vector<int>&candidates,vector<vector<int>>&ans,vector<int>&ds){
    if(ind == n) {
        if(target == 0) {
            ans.push_back(ds);
           
        }
         return ;
    }
    if(candidates[ind]<= target) {
        ds.push_back(candidates[ind]);
        findCombination(ind,n,target-candidates[ind],candidates,ans,ds);
        ds.pop_back();
    }
     findCombination(ind+1,n,target,candidates,ans,ds);

 }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        int n = candidates.size();
        findCombination(0,n,target,candidates,ans,ds);
        return ans;
    }
};