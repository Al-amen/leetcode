class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
       
         set<vector<int>>s;
        for(int i = 0; i < n; i++) {
            
            int j = i+1, k = n-1;
           
            while(j < k) {
               int x = nums[i] + nums[j] + nums[k];
                if( x == 0) {
                    s.insert({nums[i],nums[j],nums[k]});
                    j++,k--;
                                        
                }
                else if(x > 0) {
                    k--;
                }
                else {
                    j++;
                }
            }
        }
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
        
    }
};