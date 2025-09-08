class Solution {

public:
    void f(vector<int>&nums, vector<int> & sub, vector<vector<int>>& res,int ind) {
        int n = nums.size();
        // if(ind == n) {
        //     res.push_back(sub);
        //     return ;
        // }
        // sub.push_back(nums[ind]);
        // f(nums,sub,res,ind+1);
        // sub.pop_back();
        // f(nums,sub,res,ind+1);

        // backtraing 

        // 1 2 3 explore right elements of every elemt

        res.push_back(sub);
        for(int i = ind; i < n; i++) {
            sub.push_back(nums[i]);
            f(nums,sub,res,i+1);
            sub.pop_back();

        }
        return ;

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>sub;
        vector<vector<int>> res;

       f(nums,sub,res,0);
       return  res;
    }
};