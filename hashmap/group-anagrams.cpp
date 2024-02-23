class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;

        for(int i = 0; i < strs.size(); i++) {
            string t = strs[i];
            sort(t.begin(), t.end());

            m[t].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        unordered_map<string, vector<string>>::iterator itr;

        for(itr = m.begin(); itr != m.end(); itr++) {
            ans.push_back(itr->second);
        }

        return ans;
    }
};