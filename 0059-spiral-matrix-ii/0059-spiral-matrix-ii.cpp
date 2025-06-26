class Solution {
public:

        // 1  2   3   4 
        // 5  6   7   8
        // 9. 10  11 12
        // 13 14  15 16

        // 1 2 3 4  8 12 16 15 14 13 9 5 
        // top -> left to right: top+1 
        // right -> top to bottom: right-1
        // bottom -> right to left: bottom-1
        // left -> bottom to top: left-1


    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,0));

        int top = 0, bottom = n-1;
        int left = 0, right = n-1;
        
        int direction = 0;
        int val = 1;
        while(left <= right && top <= bottom) {
            if(direction == 0) {
                // top -> left to right: top+1 
                for(int col = left; col <= right; col++) {
                    ans[top][col] += val;
                    val++;
                }
                top++;
            }
            else if(direction == 1) {
                // right -> top to bottom: right-1
                for(int row = top; row <= bottom; row++) {
                    ans[row][right] = val;
                    val++;
                }
                right--;
            }

            else if(direction == 2) {
                 // bottom -> right to left: bottom-1
                for(int col = right; col >= left; col--) {
                    ans[bottom][col] = val;
                    val++;
                }
                bottom--;
            }

            else if(direction == 3) {
                // left -> bottom to top: left-1
                for(int row = bottom; row >= top; row--) {
                    ans[row][left] = val;
                    val++;
                }
                left++;
            }
            direction = (direction + 1) % 4;

        }
        return ans;

        
    }
};