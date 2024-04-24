class Solution {
public:

    int tribonacci(int n) {
        int dp[38];

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        return dp[n];
    }
};


class Solution {
public:

    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 | n == 2) return 1;

        int a = 0;
        int b = 1;
        int c = 1;

        int ans;
        for(int i = 3; i <= n; i++) {
            ans = a + b + c;

            a = b;
            b = c;
            c = ans;
        }

        return ans;
    }
};