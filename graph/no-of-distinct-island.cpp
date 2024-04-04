https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1


//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<bool>>& visited, vector<vector<int>>& grid, int i, int j, int n, int m, int si, int sj, vector<pair<int, int>>& v) {
        visited[i][j] = true;
        v.push_back(make_pair(i - si, j - sj));


        int row[] = {-1, 0 , 1, 0};
        int col[] = {0, -1, 0, 1};


        for(int k = 0; k < 4; k++) {
            int ni = i + row[k];
            int nj = j + col[k];


            if(ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj] && grid[ni][nj]) {
                dfs(visited, grid, ni, nj, n, m, si, sj, v);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited;

        for(int i = 0; i < n; i++) {
            vector<bool> v;
            for(int j = 0; j < m; j++) {
                v.push_back(false);
            }

            visited.push_back(v);
        }


        set<vector<pair<int, int>>> s;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j] && grid[i][j]) {
                    vector<pair<int, int>> v;
                    dfs(visited, grid, i, j, n, m, i, j, v);
                    s.insert(v);
                }
            }
        }

        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends