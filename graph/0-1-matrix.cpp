class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans;
        vector<vector<bool>> visited;
        queue<pair<int, int>> q;

        for(int i = 0; i < mat.size(); i++) {
            vector<int> a;
            vector<bool> v;
            for(int j = 0; j < mat[i].size(); j++) {
                a.push_back(INT_MAX);
                v.push_back(false);

                if(!mat[i][j]) {
                    q.push(make_pair(i, j));
                }
            }
            ans.push_back(a);
            visited.push_back(v);
        }

        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            visited[i][j] = true;

            if(mat[i][j] == 0) {
                ans[i][j] = 0;
            }
            else {
                int a = i - 1 >= 0 ? ans[i-1][j] : INT_MAX;
                int b = i + 1 < mat.size() ? ans[i+1][j] : INT_MAX;
                int c = j - 1 >= 0 ? ans[i][j-1] : INT_MAX;
                int d = j + 1 < mat[0].size() ? ans[i][j+1] : INT_MAX;

                int e = min(a, b);
                int f = min(c, d);

                int g = min(e, f);

                ans[i][j] = g + 1;
            }

            if(i-1 >=0 && !visited[i-1][j]) {
                    q.push(make_pair(i-1, j));
                }

                if(i+1 < mat.size() && !visited[i+1][j]) {
                    q.push(make_pair(i+1, j));
                }

                if(j-1 >= 0 && !visited[i][j-1]) {
                    q.push(make_pair(i, j-1));
                }

                if(j+1 < mat[0].size() && !visited[i][j+1]) {
                    q.push(make_pair(i, j+1));
                }
        }

        return ans;

    }
};