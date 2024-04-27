#question: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<vector<int>> adj(N);
        vector<bool> visited(N, false);
        vector<int> dist(N, -1);

        for(auto edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];

            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }

        queue<int> q;

        q.push(src);
        visited[src] = true;
        dist[src] = 0;

        while(!q.empty()) {
            int front = q.front();
            q.pop();

            for(auto nbr : adj[front]) {
                if(!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                    dist[nbr] = dist[front] + 1;
                }
            }
        }

        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends