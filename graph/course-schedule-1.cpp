class Solution {
public:
    bool checkCycle(vector<vector<int>>& adj, vector<int>& visited, int node) {
        visited[node] = 2;

        for(int i = 0; i < adj[node].size(); i++) {
            if(visited[adj[node][i]] == 2) return true;

            if(!visited[adj[node][i]]) {
                if(checkCycle(adj, visited, adj[node][i])) return true;
            }
        }

        visited[node] = 1;

        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> v;
        vector<vector<int>> adj(numCourses, v );

        for(int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<int> visited(numCourses, 0);

        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                if(checkCycle(adj, visited, i)) return false;
            }
        }

        return true;
    }
};