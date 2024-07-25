class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> luckyNumbers;
        
        for (int i = 0; i < m; ++i) {
            int row_min = INT_MAX;
            int min_col_index = -1;
            
            // Find the minimum element in the row
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] < row_min) {
                    row_min = matrix[i][j];
                    min_col_index = j;
                }
            }
            
            // Check if this minimum element is the maximum in its column
            bool is_max_in_col = true;
            for (int k = 0; k < m; ++k) {
                if (matrix[k][min_col_index] > row_min) {
                    is_max_in_col = false;
                    break;
                }
            }
            
            if (is_max_in_col) {
                luckyNumbers.push_back(row_min);
            }
        }
        
        return luckyNumbers;
    }
};