class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st; // stores indices
        int water = 0;
        vector<int>preMax(n,0);
        vector<int>suffMax(n,0);

        preMax[0] = height[0];
        suffMax[n-1] = height[n-1];

        for(int i = 1; i < n; i++) {
            preMax[i] = max(preMax[i-1],height[i]);
        }

        for(int i = n-2; i >= 0; i--) {
            suffMax[i] = max(suffMax[i+1],height[i]);
        }

        for(int i = 0; i < n; i++) {
            
            water += min(preMax[i] , suffMax[i]) - height[i];
        }

        return water;

        
    }
};
