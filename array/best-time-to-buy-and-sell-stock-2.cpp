class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1) return 0;

        int ans = 0;

        int index = 0;

        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i - 1]) {
                index = i - 1;
                break;
            }
        }

        int j = index + 1;
        while(j < prices.size()) {
            if(prices[j] < prices[j-1]) {
                ans = ans + prices[j - 1] - prices[index];
                index = j;
            }
            j++;
        }

        if(j > index) {
            ans = ans + prices[j-1] - prices[index];
        }

        return ans;
    }
};