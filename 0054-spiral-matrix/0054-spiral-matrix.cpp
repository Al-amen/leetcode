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

        
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        int top = 0, bottom = n-1;
        int left = 0, right = m-1;

        int len = n*m;
        int direction = 0;

        vector<int>ans;

        while(top <= bottom && left <= right) {

            if(direction == 0) {
                // top -> left to right: top+1 
                for(int col = left; col <= right; col++) {
                    ans.push_back(matrix[top][col]);
                }
                top++;

            }
            else if(direction == 1) {
                //right -> top to bottom: right-1
                for(int row = top; row <= bottom; row++) {
                    ans.push_back(matrix[row][right]);
                }
                right--;
            }
            else if(direction == 2) {
                //bottom -> right to left: bottom-1
                for(int col = right; col >= left; col--) {
                    ans.push_back(matrix[bottom][col]);
                }
                bottom--;

            }
            else if(direction == 3) {
                // left -> bottom to top: left-1
                for(int row = bottom; row >= top; row--) {
                    ans.push_back(matrix[row][left]);
                }
                left++;

            }

            direction = (direction + 1) % 4;
            
        }
        return ans;
        
    }
};