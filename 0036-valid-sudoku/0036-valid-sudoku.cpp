class Solution {
public:
    bool issafe(int row, int col, vector<vector<char>>& board, char ch) {
        for (int i = 0; i < 9; i++) {
            if (i != col && board[row][i] == ch)
                return false;

            if (i != row && board[i][col] == ch)
                return false;

            int r = 3 * (row / 3) + i / 3;
            int c = 3 * (col / 3) + i % 3;

            if ((r != row || c != col) && board[r][c] == ch)
                return false;
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {

                if (board[row][col] != '.') {
                    if (!issafe(row, col, board, board[row][col]))
                        return false;
                }

            }
        }

        return true;
    }
};