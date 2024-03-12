class Solution {
public:
    int getRow(vector<vector<int>>& matrix, int target, int left, int right, int col) {
        if(left > right) return -1;

        int mid = left + (right - left)/2;
        int ans;

        if(target>= matrix[mid][0] && target <= matrix[mid][col]) return mid;

        if(target < matrix[mid][0]) {
            ans = getRow(matrix, target, left, mid - 1, col);
        }
        else {
            ans = getRow(matrix, target, mid + 1, right, col);
        }

        return ans;
    }

    bool findTarget(vector<vector<int>>& matrix, int target, int row, int left, int right) {
        if(left > right) return false;

        int mid = left + (right - left)/2;
        bool ans;

        if(target == matrix[row][mid]) return true;

        if(target < matrix[row][mid]) ans = findTarget(matrix, target, row, left, mid - 1);
        else ans = findTarget(matrix, target, row, mid + 1, right);

        return ans;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size() - 1;
        int n = matrix[0].size() - 1;
        int row = getRow(matrix, target, 0, m, n);

        if(row == -1) return false;

        return findTarget(matrix, target, row, 0, n);
    }
};