#O(N^3) solution space O(1)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        int n = grid.size();

        for(int i = n - 2; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                int a = INT_MAX;
                for(int k = 0; k < n; k++) {
                    if(j == k) continue;

                    a = min(a, grid[i + 1][k]);
                }

                grid[i][j] = a + grid[i][j];
            }
        }

        for(int i = 0; i < n; i++) ans = min(ans, grid[0][i]);

        return ans;
    }
};


#O(N^2) solution space O(1)


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        int n = grid.size();

        for(int i = n - 2; i >= 0; i--) {
            int min1 = INT_MAX, min2 = INT_MAX;
            for(int k = 0; k < n; k++) {
                    if(grid[i+1][k] < min1) {
                        min2 = min1;
                        min1 = grid[i+1][k];
                    }
                    else if(grid[i+1][k] < min2) {
                        min2 = grid[i+1][k];
                    }
            }

            for(int j = 0; j < n; j++) {
                if(grid[i+1][j] == min1) {
                    grid[i][j] = min2 + grid[i][j];
                }
                else {
                    grid[i][j] = min1 + grid[i][j];
                }

            }
        }

        for(int i = 0; i < n; i++) ans = min(ans, grid[0][i]);

        return ans;
    }
};