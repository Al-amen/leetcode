class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int ans = 0;

        while(l < r) {
            int width = r-l;
            int min_height = min(height[l],height[r]);
            int area = width * min_height;
            ans = max(ans, area);
            if(height[l] < height[r]) {
                l++;
            }
            else {
                r--;
            }

        }
        return ans;
        
        
    }
};