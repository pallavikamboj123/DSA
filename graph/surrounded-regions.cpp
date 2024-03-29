class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, int n, int m, char val) {
        visited[i][j] = true;
        board[i][j] = val;

        if(i-1 >= 0 && !visited[i-1][j] && board[i-1][j] == 'O') {
            dfs(board, visited, i-1, j, n, m, val);
        }

        if(i+1 < n && !visited[i+1][j] && board[i+1][j] == 'O') {
            dfs(board, visited, i+1, j, n, m, val);
        }

        if(j+1 < m && !visited[i][j+1] && board[i][j+1] == 'O') {
            dfs(board, visited, i, j+1, n, m, val);
        }

        if(j-1 >= 0 && !visited[i][j-1] && board[i][j-1] == 'O') {
            dfs(board, visited, i, j-1, n, m, val);
        }
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> visited;
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++) {
            vector<bool> v;
            for(int j = 0; j < m; j++) {
                v.push_back(false);
            }
            visited.push_back(v);
        }

        for(int i = 0; i < n; i++) {
            if(!visited[i][0] && board[i][0] == 'O') {
                dfs(board, visited, i, 0, n, m, 'A');
            }
        }

        for(int i = 0; i < n; i++) {
            if(!visited[i][m-1] && board[i][m-1] == 'O') {
                dfs(board, visited, i, m-1, n, m, 'A');
            }
        }

        for(int j = 0; j < m; j++) {
            if(!visited[0][j] && board[0][j] == 'O') {
                dfs(board, visited, 0, j, n, m, 'A');
            }
        }

        for(int j = 0; j < m; j++) {
            if(!visited[n-1][j] && board[n-1][j] == 'O') {
                dfs(board, visited, n-1, j, n, m, 'A');
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j] && board[i][j] == 'O') {
                    dfs(board, visited, i, j, n, m, 'X');
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'A') {
                    board[i][j] = 'O';
                }
            }
        }

        return;
    }
};