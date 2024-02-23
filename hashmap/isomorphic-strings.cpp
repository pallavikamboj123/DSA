class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m;

        if(s.length() != t.length()) return false;

        for(int i = 0; i <s.length(); i++) {
            bool mapping_exists = false;

            unordered_map<char, char>::iterator itr;

            for(itr = m.begin(); itr != m.end(); itr++) {
                if(itr->second == t[i]) mapping_exists = true;
            }

            if(!m.count(s[i]) && !mapping_exists) {
                m[s[i]] = t[i];
            }

            if(m[s[i]] != t[i]) return false;
        }

        return true;
    }
};