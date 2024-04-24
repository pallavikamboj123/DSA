class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> outDegree(n, 0), ans;

        vector<vector<int>> adj(n);


        for(int i = 0; i < n; i++) {
            for(auto j : graph[i]) {
                adj[j].push_back(i);
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            outDegree[i] += graph[i].size();
            if(!outDegree[i]) q.push(i);
        }

        while(!q.empty()) {
            int front = q.front();
            q.pop();

            ans.push_back(front);

            for(auto nbr: adj[front]) {
                if(--outDegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};


//In degree solution

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> inDegree(n, 0), ans;

        vector<vector<int>> adj(n);


        for(int i = 0; i < n; i++) {
            for(auto j : graph[i]) {
                adj[j].push_back(i);
                inDegree[i]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(!inDegree[i]) q.push(i);
        }

        while(!q.empty()) {
            int front = q.front();
            q.pop();

            ans.push_back(front);

            for(auto nbr: adj[front]) {
                if(--inDegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};