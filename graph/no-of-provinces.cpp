class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        queue<int> q;
        int n = isConnected.size();
        bool visited[n];
        int count = 0;

        for(int i = 0; i < n; i++) visited[i] = false;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                q.push(i);

                while(!q.empty()) {
                    int top = q.front();
                    q.pop();
                    visited[top] = true;

                    for(int j = 0; j < n; j++) {
                        if(!visited[j] && i != j && isConnected[top][j]) {
                            q.push(j);
                        }
                    }
                }
                count++;
            }
        }

        return count;
    }
};