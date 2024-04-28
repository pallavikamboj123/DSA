class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);
        vector<int> ans;

        if(n == 1) {
            ans.push_back(0);
            return ans;
        }

        for(auto edge: edges) {
            int node1 = edge[0];
            int node2 = edge[1];

            adj[node1].push_back(node2);
            adj[node2].push_back(node1);

            inDegree[node1]++;
            inDegree[node2]++;
        }

        queue<int> q;

        for(int i = 0; i < n; i++) {
            if(inDegree[i] == 1) q.push(i);
        }

        int processed = 0;
        while(n - processed > 2) {
            int size = q.size();

            processed += size;

            for(int i = 0; i < size; i++) {
                int front = q.front();
                q.pop();

                for(auto nbr: adj[front]) {
                    if(--inDegree[nbr] == 1) q.push(nbr);
                }
            }
        }

        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};