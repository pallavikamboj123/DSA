class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();

        bool visited[m][n];

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                visited[i][j] = false;
            }
        }

        int row = 0, col = 0, a = 0;

        while(!visited[row][col]) {
            int i = col;

            for(i; i < (n - a); i++ ) {
                if(visited[row][i]) return ans;
                visited[row][i] = true;
                ans.push_back(matrix[row][i]);
            }

            i = i - 1 >=0 ? i - 1 : i;
            int j = row + 1;

            for(j; j < (m - a); j++) {
                if(visited[j][i]) return ans;
                visited[j][i] = true;
                ans.push_back(matrix[j][i]);
            }

            i = i - 1 >= 0 ? i - 1 : i;
            j = j - 1 >= 0 ? j - 1 : j;

            for(i; i >= a; i--) {
                if(visited[j][i]) return ans;
                visited[j][i] = true;
                ans.push_back(matrix[j][i]);
            }

            j = j - 1 >= 0 ? j - 1 : j;
            i = i + 1 < n ? i + 1 : i;

            for(j; j >= (a+1); j--) {
                if(visited[j][i]) return ans;
                visited[j][i] = true;
                ans.push_back(matrix[j][i]);
            }

            row++;
            col++;
            a++;

        }

        return ans;
    }
};