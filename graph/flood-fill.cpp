class Solution {
public:
    void dfs(vector<vector<int>>& image, vector<vector<bool>>& visited, int sr, int sc, int color, int org) {
        if(visited[sr][sc]) return;

        visited[sr][sc] = true;
        image[sr][sc] = color;

        if(sc - 1 >= 0 && image[sr][sc-1] == org) {
            dfs(image, visited, sr, sc - 1, color, org);
        }

        if(sc + 1 < image[0].size() && image[sr][sc + 1] == org) {
            dfs(image, visited, sr, sc + 1, color, org);
        }

        if(sr - 1 >= 0 && image[sr - 1][sc] == org) {
            dfs(image, visited, sr - 1, sc, color, org);
        }

        if(sr + 1 < image.size() && image[sr + 1][sc] == org) {
            dfs(image, visited, sr + 1, sc, color, org);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        vector<vector<bool>> visited;

        for(int i = 0; i < n; i++) {
            vector<bool> v;

            for(int j = 0; j < image[i].size(); j++) {
                v.push_back(false);
            }

            visited.push_back(v);
        }

        dfs(image, visited, sr, sc, color, image[sr][sc]);

        return image;
    }
};