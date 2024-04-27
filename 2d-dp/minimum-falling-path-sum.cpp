# TLE solution
class Solution {
public:
    int dp(vector<vector<int>>& matrix, int sum, int row, int col) {
        if(row == matrix.size()) {
            return sum;
        }

        int ans1 = INT_MAX, ans2 = INT_MAX, ans3 = INT_MAX;

        if(col - 1 >= 0) {
            ans1 = dp(matrix, sum + matrix[row][col], row + 1, col -1);
        }

        if(col + 1 < matrix.size()) {
            ans2 = dp(matrix, sum + matrix[row][col], row + 1, col + 1);
        }

        ans3 =  min(ans1, dp(matrix, sum + matrix[row][col], row + 1, col));

        return min(ans2, ans3);

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix.size();

        for(int i = 0; i < n; i++) {
            ans = min(ans, dp(matrix, 0, 0, i));
        }

        return ans;
    }
};

#memoization solution

class Solution {
public:
    int dp(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& memo) {
        if(row == matrix.size()) {
            return 0;
        }

        if(memo[row][col] != INT_MAX) return memo[row][col];

        int ans1 = INT_MAX, ans2 = INT_MAX, ans3 = INT_MAX;

        if(col - 1 >= 0) {
            ans1 = dp(matrix, row + 1, col -1, memo);
        }

        if(col + 1 < matrix.size()) {
            ans2 = dp(matrix, row + 1, col + 1, memo);
        }

        ans3 =  min(ans1, dp(matrix, row + 1, col, memo));

        int ans = min(ans2, ans3) + matrix[row][col];

        memo[row][col] = ans;

        return ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix.size();
        vector<vector<int>> memo;


        for(int i = 0 ; i < n; i++) {
            vector<int> cols;
            for(int j = 0; j < n; j++) {
                cols.push_back(INT_MAX);
            }

            memo.push_back(cols);
        }

        for(int i = 0; i < n; i++) {
            ans = min(ans, dp(matrix, 0, i, memo));
        }

        return ans;
    }
};


#iterative dp solution

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = n -2; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                int a = INT_MAX;

                if(j - 1 >= 0) {
                    a = min(a, matrix[i + 1][j - 1]);
                }

                if(j + 1 < n) a = min(a, matrix[i + 1][j + 1]);

                a = min(a, matrix[i+1][j]) + matrix[i][j];

                matrix[i][j] = a;
            }
        }

        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            ans = min(ans, matrix[0][i]);
        }

        return ans;
    }
};