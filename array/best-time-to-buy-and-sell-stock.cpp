class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int val = INT_MAX;

        for(int i = 0; i < prices.size(); i++) {
            if(val > prices[i]) val = prices[i];

            ans = max(ans, prices[i] - val);
        }

        return ans;
    }
};