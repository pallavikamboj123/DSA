class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> m;
        int ans = INT_MAX;

        for(int i = 0; i < cards.size(); i++) {
            if(m.count(cards[i])) {
                ans = min(ans, i - m[cards[i]] + 1);
            }
            m[cards[i]] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};