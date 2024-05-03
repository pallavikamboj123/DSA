class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> time(n + 1, INT_MAX);

        vector<vector<pair<int, int>>> adj(n+1, vector<pair<int, int>>(n+1));

        for(auto time: times) {
            adj[time[0]].push_back({time[1], time[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, k});

        time[k] = 0;

        while(!pq.empty()) {
            int t = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto nbr: adj[node]) {
                if(time[nbr.first] > t + nbr.second) {
                    time[nbr.first] = t + nbr.second;
                    pq.push({time[nbr.first], nbr.first});
                }
            }
        }

        int ans = *max_element(time.begin() + 1, time.end());

        return ans == INT_MAX ? -1 : ans;
    }
};