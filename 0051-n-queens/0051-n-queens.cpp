class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n) {
        // Check upper column
        for(int i = 0; i < row; i++) {
            if(board[i][col] == 'Q') return false;
        }

        // Check upper left diagonal
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q') return false;
        }

        // Check upper right diagonal
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }

    void nQueen(vector<string>& board, vector<vector<string>>& ans, int n, int row) {
        if(row == n) {
            ans.push_back(board);  // Correct way to store current board config
            return;
        }

        for(int col = 0; col < n; col++) {
            if(isSafe(board, row, col, n)) {
                board[row][col] = 'Q';           // Choose
                nQueen(board, ans, n, row + 1);  // Explore
                board[row][col] = '.';           // Unchoose (backtrack)
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;

        nQueen(board, ans, n, 0);

        return ans;
    }
};
