class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> dist(n, INT_MIN);

        vector<pair<int, double>> adj[n+1];

        for(int i = 0; i < edges.size(); i++) {
            int node1 = edges[i][0];
            int node2 = edges[i][1];

            adj[node1].push_back({node2, succProb[i]});
            adj[node2].push_back({node1, succProb[i]});
        }

        priority_queue<pair<double, int>> p;

        p.push({1, start_node});

        dist[start_node] = 1;

        while(!p.empty()) {
            double d = p.top().first;
            int node = p.top().second;
            p.pop();

            if(node == end_node) return dist[node];

            for(auto nbr: adj[node]) {

                if(dist[nbr.first] < d * nbr.second) {
                    dist[nbr.first] = d * nbr.second;
                    p.push({dist[nbr.first], nbr.first});
                }
            }
        }

        return 0.00;
    }
};