class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;

        if(s.length() != t.length()) return false;

        for(int i = 0; i < s.length(); i++) {
            if(!m.count(s[i])) {
                m[s[i]] = 1;
            }
            else{
                m[s[i]] = m[s[i]] + 1;
            }
        }

        for(int i = 0; i < t.length(); i++) {
            if(!m.count(t[i]) || !m[t[i]]) return false;

            m[t[i]] = m[t[i]] - 1;
        }

        return true;
    }
};