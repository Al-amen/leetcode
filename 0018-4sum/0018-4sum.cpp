class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i-1])continue;

            for(int j = i+1; j < n; j++) {
                if(j != i+1 && nums[j] == nums[j-1])continue;
                int k = j+1, l = n-1;

                while(k < l) {
                    long long x = nums[i];
                    x += nums[j];
                    x += nums[k];
                    x += nums[l];

                    if(x == target) {
                        vector<int>temp = {nums[i],nums[j],nums[k],nums[l]};
                        
                        ans.push_back(temp);
                        l--;
                        k++;
                        while(k < l and nums[k] == nums[k-1]) {
                            k++;
                        }
                         while(k < l and nums[l] == nums[l+1]) {
                            l--;
                        }
                    }
                    else if(x < target) k++;
                    else l--;
                   
                }
            }
        }
        return ans;
        
    }
};