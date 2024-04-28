#TLE solution (Brute force)

class Solution {
public:
    int dfs(vector<vector<int>>& tri, int row, int col) {
        if(row == tri.size()) return 0;

        int ans = INT_MAX;

        ans = min(ans, dfs(tri, row + 1, col));

        if(col + 1 < tri.size())
            ans = min(ans, dfs(tri, row + 1, col + 1));

        return ans + tri[row][col];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        return dfs(triangle, 0, 0);
    }
};

#memo solution

class Solution {
public:
    int dfs(vector<vector<int>>& tri, int row, int col, vector<vector<int>>& memo) {
        if(row == tri.size()) return 0;

        if(memo[row][col] != INT_MAX) return memo[row][col];
        int ans = INT_MAX;

        ans = min(ans, dfs(tri, row + 1, col, memo));

        if(col + 1 < tri.size())
            ans = min(ans, dfs(tri, row + 1, col + 1, memo));

        memo[row][col] = ans + tri[row][col];

        return ans + tri[row][col];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> memo;
        int n = triangle.size();

        for(auto tri: triangle) {
            vector<int> v;

            for(auto t: tri) {
                v.push_back(INT_MAX);
            }

            memo.push_back(v);
        }

        return dfs(triangle, 0, 0, memo);
    }
};