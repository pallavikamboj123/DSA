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


# dfs solution where use parent node to find the ans (ans = ans of parent - no of nodes of child including child + remaning nodes)

class Solution {
public:
    int totalSum = 0;
    int dfs(vector<vector<int>>& adj, int node, int level, vector<bool>& visited, vector<int>& child) {
        visited[node] = true;

        totalSum += level;
        int ch = 0;

        for(auto nbr : adj[node]) {
            if(!visited[nbr]) {
                ch += dfs(adj, nbr, level + 1, visited, child );
            }
        }

        child[node] = ch + 1;

        return ch + 1;
    }

    void dfs2(vector<vector<int>>& adj, int node, int parent, vector<int>& dist, vector<bool>& visited, vector<int>& child, int n) {
        visited[node] = true;
        cout<<node<<" "<<parent<<endl;

        for(auto nbr: adj[node]) {
            if(!visited[nbr]) {

                dist[nbr] = dist[node] - child[nbr] +  (n - child[nbr]);


                dfs2(adj, nbr, node, dist, visited, child, n);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> dist(n);
        vector<int> child(n, 0);
        vector<vector<int>> adj(n);

        for(auto edge: edges) {
            int node1 = edge[0];
            int node2 = edge[1];

            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }

        vector<bool> visited(n, false);


        child[0] = dfs(adj, 0, 0, visited, child);

        dist[0] = totalSum;

        for(int i = 0; i < n; i++) visited[i] = false;

        dfs2(adj, 0, -1, dist, visited, child, n);

        return dist;
    }
};

#sol after refactoring

class Solution {
public:
    int totalSum = 0;
    vector<int> child;
    int dfs(vector<vector<int>>& adj, int node, int level, int preNode) {
        totalSum += level;
        int ch = 0;

        for(auto nbr : adj[node]) {
            if(nbr == preNode) continue;

            ch += dfs(adj, nbr, level + 1, node);
        }

        child[node] = ch + 1;
        return ch + 1;
    }

    void dfs2(vector<vector<int>>& adj, int node, int prevNode, vector<int>& dist, int n) {

        for(auto nbr: adj[node]) {
            if(nbr == prevNode) continue;

            dist[nbr] = dist[node] - child[nbr] +  (n - child[nbr]);
            dfs2(adj, nbr, node, dist, n);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> dist(n);
        vector<vector<int>> adj(n);

        child.resize(n, 0);

        for(auto edge: edges) {
            int node1 = edge[0];
            int node2 = edge[1];

            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }

        dfs(adj, 0, 0, -1);

        dist[0] = totalSum;

        dfs2(adj, 0, -1, dist, n);

        return dist;
    }
};