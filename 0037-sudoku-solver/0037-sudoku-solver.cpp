class Solution {
public:
    bool safe(vector<vector<char>>& board, int num, int row, int col) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == num) {
                return false;
            }
        }
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == num) {
                return false;
            }
        }
        int bsr = (row / 3) * 3;
        int bsc = (col / 3) * 3;
        for (int i = bsr; i < bsr + 3; i++) {
            for (int j = bsc; j < bsc + 3; j++) {
                if (board[i][j] == num) {
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (int num = '1'; num <= '9'; num++) {
                        if(safe(board,num,i,j)){
                            board[i][j] = num;
                            if (solve(board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
                
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};