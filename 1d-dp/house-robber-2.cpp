class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        if(n == 2) return max(nums[0], nums[1]);

        int dp[n];

        for(int i = 0; i < n; i++ ) {
            dp[i] = INT_MIN;
        }

        int ans = INT_MIN;

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        ans = max(ans, dp[1]);

        for(int i = 2; i < n-1; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i-1]);
            ans = max(dp[i], ans);
        }


        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);

        ans = max(ans, dp[2]);

        for(int i = 3; i < n; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i-1]);
            ans = max(dp[i], ans);
        }

        return ans;
    }
};