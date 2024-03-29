class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int n, int m) {
        visited[i][j] = true;

        int count = 0;

        if(i-1 >= 0 && !visited[i-1][j] && grid[i-1][j]) {
            count += dfs(grid, visited, i - 1, j, n, m) + 1;
        }
        if(i+1 < n && !visited[i+1][j] && grid[i+1][j]) {
            count += dfs(grid, visited, i + 1, j, n, m) + 1;
        }
        if(j+1 < m && !visited[i][j+1] && grid[i][j+1]) {
            count += dfs(grid, visited, i, j + 1, n, m) + 1;
        }
        if(j-1 >= 0 && !visited[i][j-1] && grid[i][j-1]) {
            count += dfs(grid, visited, i, j - 1, n, m) + 1;
        }

        return count;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<bool>> visited;
        int n = grid.size();
        int m = grid[0].size();
        int total = 0;
        for(int i = 0; i < n; i++) {
            vector<bool> v;
            for(int j= 0; j < m; j++) {
                v.push_back(false);
                if(grid[i][j]) total++;
            }
            visited.push_back(v);
        }

        int count = 0;

        for(int j = 0; j < m; j++) {
            if(!visited[0][j] && grid[0][j]) {
                int a = dfs(grid, visited, 0, j, n, m) + 1;
                count += a;
            }
        }

        for(int j = 0; j < m; j++) {
            if(!visited[n-1][j] && grid[n-1][j]) {
                int a = dfs(grid, visited, n-1, j, n, m) + 1;
                count += a;
            }
        }

        for(int i = 0; i < n; i++) {
            if(!visited[i][0] && grid[i][0]) {
                int a = dfs(grid, visited, i, 0, n, m) + 1;
                count += a;
            }
        }

        for(int i = 0; i < n; i++) {
            if(!visited[i][m-1] && grid[i][m-1]) {
                int a = dfs(grid, visited, i, m-1, n, m) + 1;
                count += a;
            }
        }

        return total - count;
    }
};