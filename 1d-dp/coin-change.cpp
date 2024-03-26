class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int arr[amount + 1];

        for(int i = 0; i <= amount; i++) arr[i] = INT_MAX;

        if(!amount) return amount;

        for(int i = 0; i < coins.size(); i++) {
            int coin = coins[i];

            if(coin > amount) continue;

            arr[coin] = 1;

            for(int j = coin + 1; j <= amount; j++) {
                int val = arr[j - coin];

                if(val == INT_MAX) continue;

                arr[j] = min(arr[j], val + 1);
            }
        }

        return arr[amount] == INT_MAX ? -1 : arr[amount];
    }
};