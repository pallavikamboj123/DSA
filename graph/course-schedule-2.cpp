//DFS SOL
class Solution {
public:
    vector<int> ans;

    bool topoSort(vector<vector<int>>& adj, vector<int>& visited, int node) {
        visited[node] = 2;

        vector<int> neighbors = adj[node];

        for(int i = 0; i < neighbors.size(); i++) {
            if(visited[neighbors[i]] == 2) return true;

            if(!visited[neighbors[i]]) {
                if(topoSort(adj, visited, neighbors[i])) return true;
            }
        }

        visited[node] = 1;

        ans.push_back(node);

        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> v;
        vector<vector<int>> adj(numCourses, v );

        for(int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<int> visited(numCourses, 0);

        bool isPossible = true;
        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                if(topoSort(adj, visited, i)) {
                    isPossible = false;
                    break;
                }
            }
        }

        if(isPossible) return ans;

        return {};
    }
};


//Add BFS sol
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0), ans;
        queue<int> q;

        for(auto p: prerequisites) {
            adj[p[1]].push_back(p[0]);
            inDegree[p[0]]++;
        }

        for(int i = 0; i < numCourses; i++) {
            if(!inDegree[i]) q.push(i);
        }

        while(!q.empty()) {
            int front = q.front();
            q.pop();

            ans.push_back(front);

            for(auto nextCourse: adj[front]) {
                if(--inDegree[nextCourse] == 0) q.push(nextCourse);
            }
        }

        if(ans.size() == numCourses) return ans;

        return {};
    }
};