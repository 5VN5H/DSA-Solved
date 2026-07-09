class Solution {
public:
    bool ifsafe(vector < string > &board, int row, int n, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        int i = row;
        int j = col;
        while(i>=0&&j>=0){
            if(board[i][j] == 'Q'){
                return false;
            }
            i--;
            j--;
        }
        i=row;
        j=col;
        while(i>=0&&j<n){
            if(board[i][j] == 'Q'){
                return false;
            }
            i--;
            j++;
        }
        return true;
    }
    void solve( vector < string > &board,
               vector<vector<string>>& ans, int row, int n) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (ifsafe(board, row, n, col)) {
                board[row][col] = 'Q';
                solve(board, ans, row + 1, n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        solve(board,ans,0,n);
        return ans;
    }
};