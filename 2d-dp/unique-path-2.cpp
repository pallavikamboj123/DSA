https://leetcode.com/problems/unique-paths-ii/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        grid[0][0] = grid[0][0] ? 0 : 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0) continue;
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    continue;
                }

                int ans = 0;
                if(i - 1 >= 0) ans += grid[i-1][j];
                if(j-1 >= 0) ans += grid[i][j-1];

                grid[i][j] = ans;
            }
        }

        return grid[n-1][m-1];
    }
};