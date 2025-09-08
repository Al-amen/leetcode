class Solution {

public:
    void f(vector<int>&nums, vector<int> & sub, vector<vector<int>>& res,int ind) {
        int n = nums.size();
        if(ind == n) {
            res.push_back(sub);
            return ;
        }
        sub.push_back(nums[ind]);
        f(nums,sub,res,ind+1);
        sub.pop_back();
        f(nums,sub,res,ind+1);


    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>sub;
        vector<vector<int>> res;

       f(nums,sub,res,0);
       return  res;
    }
};