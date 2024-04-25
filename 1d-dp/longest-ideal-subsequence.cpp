//TLE
class Solution {
public:
    int longestIdealString(string s, int k) {
        int dp[s.length()];


        int ans = INT_MIN;
        dp[0] = 1;

        for(int i = 1; i < s.length(); i++) {
            int a = INT_MIN;
            for(int j = 0; j < i; j++) {
                if(abs(s[j] - s[i]) <= k) {
                    a = max(a, dp[j]);
                }
            }

            dp[i] = a == INT_MIN ? 1 : a + 1;

            ans = max(ans, dp[i]);
        }

        return ans;
   }
};


//Solution with out TLE

class Solution {
public:
    int longestIdealString(string s, int k) {

        unordered_map<char, int> m;

        int ans = 1;

        m[s[0]] = 1;

        for(int i = 1; i < s.length(); i++) {
            int a = INT_MIN;
            for(char j = 'a'; j <= 'z'; j++) {
                if(abs(j - s[i]) <= k && m.count(j)) {
                    a = max(a, m[j]);
                }
            }

            m[s[i]] = a == INT_MIN ? 1 : a + 1;
            ans = max(ans, m[s[i]]);
        }

        return ans;
   }
};