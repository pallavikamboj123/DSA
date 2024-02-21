class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<pair<int, int>> indexes;

        for( int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!matrix[i][j]) {
                    pair<int, int> a;
                    a.first = i;
                    a.second = j;

                    indexes.push_back(a);
                }
            }
        }

        for(int i = 0; i < indexes.size(); i++) {
            pair<int, int> p = indexes[i];
            int row = p.first;
            int col = p.second;

            for(int j = row; j >= 0; j--) {
                matrix[j][col] = 0;
            }

            for(int j = row + 1; j < m; j++) {
                matrix[j][col] = 0;
            }

            for(int j = col; j >= 0; j--) {
                matrix[row][j] = 0;
            }

            for(int j = col+1; j < n; j++) {
                matrix[row][j] = 0;
            }
        }

        return;
    }
};