#TLE solution

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> dist(n);
        vector<vector<int>> adj(n);

        for(auto edge: edges) {
            int node1 = edge[0];
            int node2 = edge[1];

            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }

        for(int i = 0; i < n; i++) {
            vector<bool> visited(n, false);

            queue<pair<int, int>> q;

            q.push({i, 0});

            int sum = 0;

            while(!q.empty()) {
                int node = q.front().first;
                int level = q.front().second;
                q.pop();

                sum += level;
                visited[node] = true;

                for(auto nbr: adj[node]) {
                     if(!visited[nbr]) {
                        q.push({nbr, level + 1});
                     }
                }
            }

            dist[i] = sum;
        }

        return dist;
    }
};