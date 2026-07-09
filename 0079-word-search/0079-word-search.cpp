class Solution {
public:
    bool dfs(string& word, vector<vector<char>>& board, int row, int col,
             int index) {
        if (index == word.length()) {
            return true;
        }
        if (row < 0 || col < 0 || row >= board.size() ||
            col >= board[0].size() || word[index] != board[row][col]) {
            return false;
        }
        char ch = board[row][col];
        board[row][col] = '#';

        bool found = dfs(word, board, row + 1, col, index + 1) ||
                     dfs(word, board, row - 1, col, index + 1) ||
                     dfs(word, board, row, col + 1, index + 1) ||
                     dfs(word, board, row, col - 1, index + 1);

        board[row][col] = ch;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(dfs(word,board,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};