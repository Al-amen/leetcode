class Solution
{
    public:
          void findCombination(vector<int> &arr, vector<vector< int>> &ans, vector<int>&ds,int ind, int target){
                if(target == 0){
                    ans.push_back(ds);
                    return;
                }  

                for(int i = ind; i<arr.size(); i++) {
                    if(i > ind && arr[i] == arr[i-1])continue;
                    if(arr[i] > target)break;
                    ds.push_back(arr[i]);
                    findCombination(arr,ans,ds,i+1,target-arr[i]);
                    ds.pop_back();

                }

          }
    public:
    vector<vector < int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>ds;
        vector<vector<int>>ans;
        findCombination(candidates,ans,ds,0,target);
        return ans;


    }
};