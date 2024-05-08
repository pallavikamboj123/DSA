#using heap takes O(nlogn) time
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;

        for(int i = 0; i < score.size(); i++) {
            pq.push({score[i], i});
        }

        vector<string> ans(score.size(), "");
        int count = 0;
        while(!pq.empty()) {
            int index = pq.top().second;
            pq.pop();
            count++;
            switch(count) {
                case 1:
                    ans[index] = "Gold Medal";
                    break;
                case 2:
                    ans[index] = "Silver Medal";
                    break;
                case 3:
                    ans[index] = "Bronze Medal";
                    break;
                default:
                    ans[index] = to_string(count);
                    break;
            }
        }

        return ans;
    }
};