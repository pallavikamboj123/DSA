class Solution {
public:
    int n;
    vector<string> ans;
    void backtrack(string s, int i, string curr) {
        if(i >= n) {
            ans.push_back(curr);
            return;
        }

        if(isdigit(s[i])) {
            curr += s[i];
            backtrack(s, i + 1, curr);
        }
        else {
            curr += tolower(s[i]);

            backtrack(s, i + 1, curr);

            curr[curr.length() - 1] = toupper(s[i]);

            backtrack(s, i + 1, curr);
        }
    }

    vector<string> letterCasePermutation(string s) {
        n = s.length();
        string curr = "";

        backtrack(s, 0, curr);

        return ans;

    }
};