class Solution {
private:
    void solve(int col, int n, std::vector<std::string>& board, std::vector<std::vector<std::string>>& ans,
               std::vector<int>& leftRow, std::vector<int>& lowerDiag, std::vector<int>& upperDiag) {
        // Base case: All queens are placed successfully
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            // Check if placing a queen here is safe
            if (!leftRow[row] && !lowerDiag[row + col] && !upperDiag[(n - 1) + (col - row)]) {
                
                // Place the queen
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiag[row + col] = 1;
                upperDiag[(n - 1) + (col - row)] = 1;

                // Recurse for the next column
                solve(col + 1, n, board, ans, leftRow, lowerDiag, upperDiag);

                // Backtrack and reset state
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiag[row + col] = 0;
                upperDiag[(n - 1) + (col - row)] = 0;
            }
        }
    }

public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> ans;
        std::vector<std::string> board(n, std::string(n, '.'));

        // Optimization arrays to check safety in O(1) time
        std::vector<int> leftRow(n, 0);
        std::vector<int> lowerDiag(2 * n - 1, 0);
        std::vector<int> upperDiag(2 * n - 1, 0);

        solve(0, n, board, ans, leftRow, lowerDiag, upperDiag);
        return ans;
    }
};