class Solution {
public:

    void helper(vector<vector<char>>& grid, bool **visited, int i, int j, int n, int m) {
        if(visited[i][j]) return;

        if(grid[i][j] == '0') return;

        visited[i][j] = true;

        if(j-1 >=0) helper(grid, visited, i, j-1, n, m);

        if(j+1 < m) helper(grid, visited, i, j+1, n, m);

        if(i-1 >= 0) helper(grid, visited, i-1, j, n, m);

        if(i+1 < n) helper(grid, visited, i+1, j, n, m);

        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        bool **visited = new bool*[n];

        for(int i = 0; i < n; i++) {
            visited[i] = new bool[m];
            for(int j = 0; j < m; j++) {
                visited[i][j] = false;
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    helper(grid, visited, i, j, n, m);
                    ans++;
                }
            }
        }

        return ans;
    }
};


class Solution {
public:
    int row[4] = {0, 0, -1, 1};
    int col[4] = {-1, 1, 0, 0};

    void helper(vector<vector<char>>& grid, int i, int j, int n, int m) {
        if(i < 0 || j < 0 || i >= n || j >= m) return;
        if(grid[i][j] == '2') return;

        if(grid[i][j] == '0') return;

        grid[i][j] = '2';

        for(int k = 0; k < 4; k++) {
            int new_r = i + row[k];
            int new_c = j + col[k];

           helper(grid, new_r, new_c, n, m);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != '2' && grid[i][j] == '1') {
                    helper(grid, i, j, n, m);
                    ans++;
                }
            }
        }

        return ans;
    }
};