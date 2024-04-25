#https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
//TLE
class Solution {
  public:
    vector<int> path;
    vector<bool> visited;

    void dfs(int node, vector<vector<int>>& edges, int weight) {
        visited[node] = true;

        for(int i = 0; i < edges.size(); i++) {
            if(edges[i][0] == node) {
                path[edges[i][1]] = min(path[edges[i][1]], weight + edges[i][2]);
                dfs(edges[i][1], edges, weight + edges[i][2]);
            }
        }
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        for(int i = 0; i < N; i++) {
            path.push_back(INT_MAX);
            visited.push_back(false);
        }


        dfs(0, edges, 0);

        path[0] = 0;

        for(int i = 0; i < N; i++) {
            if(path[i] == INT_MAX) path[i] = -1;
        }

        return path;
    }
};

# solution using topo topoSor

# algo, do a topo sort and then relax the edges
class Solution {
  public:

    void topoSort(int node, vector<vector<pair<int, int>>>& adj,  vector<bool>& visited, stack<int>& st) {
        visited[node] = true;

        for(auto edge: adj[node]) {
            if(!visited[edge.first]) {
                topoSort(edge.first, adj, visited, st);
            }
        }

        st.push(node);
    }

    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<pair<int, int>>> adj(N);
        vector<bool> visited(N, false);
        stack<int> s;

        for(auto edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        topoSort(0, adj, visited, s);

        vector<int> dist(N, INT_MAX);

        dist[0] = 0;

        while(!s.empty()) {
            int top = s.top();
            s.pop();

            for(auto edge: adj[top]) {
                dist[edge.first] = min(dist[edge.first], dist[top] + edge.second);
            }
        }

        for(int i = 0; i < N; i++) {
            if(dist[i] == INT_MAX) dist[i] = -1;
        }

        return dist;
    }
};
