class Solution {
public:
    unordered_set<string> sett;
    unordered_map<string, bool> m;

    bool canBreak(string s) {
        if(!s.length()) return true;

        if(m.count(s)) return m[s];

        for(int j = 0; j < s.length(); j++){
            string sub = s.substr(0, j+1);
            if(sett.count(sub)) {
                bool ans = canBreak(s.substr(j+1));
                m[s] = ans;
                if(ans) return ans;
            }

        }

        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        for(int i = 0; i < wordDict.size(); i++) {
            sett.insert(wordDict[i]);
        }

        return canBreak(s);
    }
};