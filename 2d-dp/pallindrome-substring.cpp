#tle
class Solution {
public:
    bool countPallin(string s, int i, int j) {
        if(i > j) return true;

        if(s[i] != s[j]) return false;

        if(countPallin(s, i + 1, j - 1)) return true;

        return false;
    }
    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(countPallin(s, i, j)) ans++;
            }
        }

        return ans;
    }
};

#memo

class Solution {
public:
    bool countPallin(string s, int i, int j, vector<vector<int>>& memo) {
        if(i > j) return true;

        if(memo[i][j] != -1) return memo[i][j];

        if(s[i] != s[j]) return false;

        if(countPallin(s, i + 1, j - 1, memo)) {
            memo[i][j] = true;
            return true;

        }

        memo[i][j] = false;

        return false;
    }
    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        vector<vector<int>> memo;

        for(int i = 0 ; i < n; i++) {
            vector<int> v;
            for(int j = 0; j < n; j++) v.push_back(-1);

            memo.push_back(v);
        }

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(countPallin(s, i, j, memo)) ans++;
            }
        }

        return ans;
    }
};

#iterative dp(blueprint method)

class Solution {
public:

    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        vector<vector<bool>> dp(n);

        for(int i = 0 ; i < n; i++) {
            vector<bool> v;
            for(int j = 0; j < n; j++) v.push_back(false);

            dp.push_back(v);
        }

        for(int i = 0; i < n; i++) dp[i][i] = true;

        int i = 0;

        while(i < n - 1) {
            int a = 0, b = i + 1;

            while(b < n) {
                if(a + 1 < b - 1) {
                    dp[a][b] = (s[a] == s[b]) && dp[a+1][b-1];
                }
                else {
                    dp[a][b] = (s[a] == s[b]);
                }

                if(dp[a][b]) {
                    ans++;
                }

                a++;
                b++;
            }
            i++;
        }

        return ans + s.length();
    }
};