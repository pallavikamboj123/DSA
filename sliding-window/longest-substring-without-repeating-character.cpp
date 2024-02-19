class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int len = 0;
        unordered_map<char, int> m;

        while(j < s.length()) {
            if(m.find(s[j]) != m.end()) {
                i = max(i , m[s[j]] + 1);
            }

            len = max(len, j - i + 1);
            m[s[j]] = j;
            j++;
        }

        return len;
    }
};