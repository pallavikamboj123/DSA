#brute force
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

        priority_queue<pair<float, pair<int, int>>, vector<pair<float, pair<int, int>>>, greater<pair<float, pair<int, int>>>> pq;
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                float val = float(arr[i])/float(arr[j]);
                pq.push({val, {arr[i], arr[j]}});
            }
        }

        while(k-- > 1) {
            pq.pop();
        }

        vector<int> ans(2);
        ans[0] = pq.top().second.first;
        ans[1] = pq.top().second.second;
        return ans;
    }
};