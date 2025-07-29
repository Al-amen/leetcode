class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        const int n=nums.size();
        vector<int> ans(n);
        vector<int> last(30, -1); // last seen index of each bit

        for (int i=n-1; i>= 0; i--) {
            const unsigned x=nums[i];
            int j=i;
            bitset<30> X(x);
            for (int b=0; b<30; b++) {
                if (X[b]) 
                    last[b]=i;
                j=max(j, last[b]);
            }
            ans[i]=j-i+1;
        }

        return ans;
    }
};