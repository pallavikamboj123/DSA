class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;

        for(int i = 0; i < magazine.length(); i++) {
            if(m.count(magazine[i]) == 0) m[magazine[i]] = 1;
            else {
                m[magazine[i]] = m[magazine[i]] + 1;
            }
        }

        for(int i = 0; i < ransomNote.length(); i++) {
            char c = ransomNote[i];
            if(!m.count(c) || m[c] == 0) return false;

            m[c] = m[c] - 1;
        }

        return true;
    }
};