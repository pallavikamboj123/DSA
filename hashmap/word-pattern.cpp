class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> m;
        int count = 0;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') count++;
        }

        if(count + 1 != pattern.length()) return false;

        int j = 0;

        for(int i = 0; i < pattern.length(); i++) {
            string word = "";
            while(s[j] != ' ' && j < s.length()) {
                word += s[j];
                j++;
            }
            j++;

            unordered_map<char, string>::iterator itr;
            bool mapping_exists = false;

            for(itr = m.begin(); itr != m.end(); itr++) {
                if(itr-> second == word) mapping_exists = true;
            }

            if(!m.count(pattern[i]) && !mapping_exists) {
                m[pattern[i]] = word;
            }

            if(m[pattern[i]] != word) return false;
        }

        return true;

    }
};