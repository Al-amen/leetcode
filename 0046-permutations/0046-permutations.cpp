class Solution {
public:
    void f(vector<int> &nums, vector<int> &temp, vector<bool> &visited, vector<vector<int>> & res) {
        int n = nums.size();
        if(temp.size() == n) {
            res.push_back(temp);
            
        }

        for(int i = 0; i < n; i++) {
            if(visited[i]==true){
                continue;
            }
            visited[i] = true;
            temp.push_back(nums[i]);
            f(nums,temp, visited, res);
            temp.pop_back();
            visited[i] = false;
        }

        return ;

    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        vector<bool>visited(n,false);
        vector<vector<int>>res;
        f(nums,temp,visited,res);
        return res;
    }
};