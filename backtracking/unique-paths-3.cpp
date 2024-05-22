class Solution {
public:
    int ans = 0;

    void backtrack(vector<vector<int>>& grid, int row, int col, int total, int count) {
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == 3) return;

        if(grid[row][col] == -1) return;

        count++;
        if(grid[row][col] == 2 && count == total) {
            ans++;
            return;
        }

        int temp = grid[row][col];
        grid[row][col] = 3;

        backtrack(grid, row + 1, col, total, count);
        backtrack(grid, row - 1, col, total, count);
        backtrack(grid, row, col + 1, total, count);
        backtrack(grid, row, col - 1, total, count);

        grid[row][col] = temp;

        return;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int obst = 0;
        int n = grid.size();
        int m = grid[0].size();
        int start_row, start_col;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == -1) obst++;
                if(grid[i][j] == 1) {
                    start_row = i;
                    start_col = j;
                }
            }
        }

        backtrack(grid, start_row, start_col, n*m - obst, 0);

        return ans;
    }
};