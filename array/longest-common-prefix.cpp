class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = INT_MAX;

        for(int i = 0; i < strs.size(); i++) {
            int c = strs[i].length();
            len = min(len, c);
        }

        int i = 0;
        string ans = "";
        char curr = ' ';

        while( i < len) {
            curr = strs[0][i];
            for(int j = 1; j < strs.size(); j++) {
                if(curr != strs[j][i]) return ans;
            }
            i++;
            ans += curr;
        }

        return ans;

    }
};