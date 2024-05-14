class Solution {
public:
    int getGold(vector<vector<int>>& grid, int row, int col) {
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0) return 0;


        int curr = grid[row][col];
        grid[row][col] = 0;
        int ans = 0;

        ans = max(ans, getGold(grid, row + 1, col) + curr);
        ans = max(ans, getGold(grid, row - 1, col)+ curr);
        ans = max(ans, getGold(grid, row, col + 1)+ curr);
        ans = max(ans, getGold(grid, row, col - 1)+ curr);

        grid[row][col] = curr;
        return ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;


        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]) {
                    ans = max(ans, getGold(grid, i, j));
                }

            }
        }

        return ans;
    }
};