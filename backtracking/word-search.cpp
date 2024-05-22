class Solution {
public:
    bool backtrack(vector<vector<char>>& board, string word, int index, vector<vector<bool>>& visited, int i, int j) {
        if(index >= word.size()) return true;

        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] ){
            return false;
        }

        if(word[index] != board[i][j]) {
            return false;
        }

        visited[i][j] = true;

        if(backtrack(board, word, index + 1, visited, i + 1, j)) return true;
        if(backtrack(board, word, index + 1, visited, i - 1, j)) return true;
        if(backtrack(board, word, index + 1, visited, i, j+1)) return true;
        if(backtrack(board, word, index + 1, visited, i, j-1)) return true;

        visited[i][j] = false;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0]) {
                    if(backtrack(board, word, 0, visited, i , j)) return true;;
                }
            }
        }

        return false;
    }
};