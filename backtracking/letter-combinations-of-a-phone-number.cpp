class Solution {
public:
    vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;

    void helper(string digits, int index, string a) {
        if(index >= digits.length()) {
            ans.push_back(a);
            return;
        }

        string curr = map[digits[index]- '0'];
        for(int i = 0; i < curr.length(); i++) {
            helper(digits, index+1, a + curr[i]);
        }

        return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return ans;

        helper(digits, 0, "");

        return ans;
    }
};