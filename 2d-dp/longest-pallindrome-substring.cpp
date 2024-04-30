#memory limit excedded - Recursion
class Solution {
public:
    bool checkPallin(string s, int i, int j) {
        if(i > j) return true;

        if(s[i] != s[j]) return false;

        if(checkPallin(s, i + 1, j - 1)) return true;

        return false;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        string ans = "";

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(checkPallin(s, i, j)) {
                    ans = j - i + 1 > ans.length() ? s.substr(i, j - i + 1) : ans;
                }
            }
        }

        return ans;
    }
};

#memory limit excedded - Recursion with memo

class Solution {
public:
    bool checkPallin(string s, int i, int j, vector<vector<int>>& memo) {
        if(i > j) return true;

        if(memo[i][j] != -1) return memo[i][j];

        if(s[i] != s[j]) return false;

        if(checkPallin(s, i + 1, j - 1, memo)) {
            memo[i][j] = 1;
            return true;
        }

        memo[i][j] = 0;

        return false;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        string ans = "";

        vector<vector<int>> memo(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(checkPallin(s, i, j, memo)) {
                    ans = j - i + 1 > ans.length() ? s.substr(i, j - i + 1) : ans;
                }
            }
        }

        return ans;
    }
};


