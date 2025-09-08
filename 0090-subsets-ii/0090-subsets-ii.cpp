class Solution {
public:
    void f(vector<int>&nums, vector<int>&sub, vector<vector<int>> &res, int ind) {
        int n = nums.size();
        // if(ind == n) {
        //     res.push_back(sub);
        //     return ;
        // }
        // sub.push_back(nums[ind]);
        // f(nums,sub,res,ind+1);
        // sub.pop_back();
        // while(ind < n-1 && nums[ind] == nums[ind+1]) {
        //     ind++;
        // }
        // f(nums,sub,res,ind+1);

        // using backtracking 

        res.push_back(sub);
        for(int i = ind; i < n; i++) {
            if(i != ind && nums[i] == nums[i-1]) {
                continue;
            }
            sub.push_back(nums[i]);
            f(nums,sub,res,i+1);
            sub.pop_back();
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>sub;
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        f(nums,sub,res,0);

        return res;
        
    }
};