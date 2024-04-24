//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	vector<int> ans;
	vector<bool> visited;

	void dfs(vector<int> adj[], int node) {
	    visited[node] = true;

	    vector<int> neighbors = adj[node];

	    for(int i = 0; i < neighbors.size(); i++) {
	        if(!visited[neighbors[i]]) {
	            dfs(adj, neighbors[i]);
	        }
	    }

	    ans.push_back(node);
	}
	vector<int> topoSort(int V, vector<int> adj[])
	{
	    for(int i = 0; i < V; i++) visited.push_back(false);
	    for(int i = 0; i < V; i++) {
	        if(!visited[i]) {
	            dfs(adj, i);
	        }
	    }

	    reverse(ans.begin(), ans.end());

	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {

    if(V!=res.size())
    return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}
// } Driver Code Ends






//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	vector<int> ans;

	vector<int> topoSort(int V, vector<int> adj[])
	{
        vector<int> inDegree(V, 0);

        for(int i = 0; i < V; i++) {
            vector<int> vertices = adj[i];
            for(int j = 0; j < vertices.size(); j++) {
                inDegree[vertices[j]]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < V; i++) {
            if(!inDegree[i]) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int front = q.front();

            q.pop();

            if(!inDegree[front]) {
                ans.push_back(front);
            }

            vector<int> vertices = adj[front];

            for(int i = 0; i < vertices.size(); i++) {
                inDegree[vertices[i]]--;

                if(!inDegree[vertices[i]]) q.push(vertices[i]);
            }
        }

        // for(int i = 0; i < ans.size(); i++) cout<<ans[i]<<" ";

	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {

    if(V!=res.size())
    return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}
// } Driver Code Ends