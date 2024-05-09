class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());

        int count = 0;

        long long ans = 0;

        while(count < k) {
            ans = max(ans, ans + happiness[count] - count);
            count++;
        }

        return ans;
    }
};