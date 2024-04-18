class Solution {
public:
    int ans = 0;
    vector<vector<bool>> visited;
    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
        visited[i][j] = true;
        if(grid[i][j]) {
            if(j - 1 < 0) ans++;
            if(j + 1 >= m) ans++;

            if(i - 1 < 0) ans++;
            if(i + 1 >= n) ans++;

            if(j - 1 >= 0 && !grid[i][j-1]) ans++;
            if(j + 1 < m && !grid[i][j+1]) ans++;

            if(i - 1 >= 0 && !grid[i-1][j]) ans++;
            if(i + 1 < n && !grid[i+1][j]) ans++;
        }

        if(j - 1 >= 0 && !visited[i][j-1]) {
            dfs(grid, i, j-1, n, m);
        }

        if(j + 1 < m && !visited[i][j+1]) {
            dfs(grid, i, j+1, n, m);
        }

        if(i - 1 >= 0 && !visited[i-1][j]) {
            dfs(grid, i-1, j, n, m);
        }

        if(i + 1 < n && !visited[i+1][j]) {
            dfs(grid, i+1, j, n, m);
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++) {
            vector<bool> v;
            for(int j = 0; j < m; j++) {
                v.push_back(false);
            }
            visited.push_back(v);
        }

        dfs(grid, 0, 0, n, m);
        return ans;
    }
};











class Solution {
public:
    int ans = 0;
    vector<vector<bool>> visited;
    int row[4] = {0, 0, -1, 1 };
    int col[4] = {-1,1, 0 , 0 };

    void dfs(vector<vector<int>>& grid, int r, int c, int n, int m) {
        visited[r][c] = true;
        if(grid[r][c]) {

            for(int i = 0; i < 4; i++) {
                int new_r = r + row[i];
                int new_c = c + col[i];

                if(new_r < 0 || new_c < 0 || new_r >= n || new_c >= m) {
                    ans++;
                    continue;
                }

                if(!grid[r][new_c] || ! grid[new_r][c]) ans++;
            }
        }

        for(int i = 0; i < 4; i++) {
            int new_r = r + row[i];
            int new_c = c + col[i];

            if(new_c >= 0 && new_c < m  && grid[r][new_c] && !visited[r][new_c]) dfs(grid, r, new_c, n, m);

            if(new_r >= 0 && new_r < n && grid[new_r][c] && !visited[new_r][c]) dfs(grid, new_r, c, n, m);
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int r = -1, c = -1;

        for(int i = 0; i < n; i++) {
            vector<bool> v;
            for(int j = 0; j < m; j++) {
                if(grid[i][j] && r == -1 && c == -1) {
                    r = i;
                    c = j;
                }
                v.push_back(false);
            }
            visited.push_back(v);
        }

        dfs(grid, r, c, n, m);
        return ans;
    }
};