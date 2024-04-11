class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       unordered_map<int,  vector<vector<int>>> m;

       for(int i = 0; i < candidates.size(); i++) {
            int candidate = candidates[i];
            vector<int> v;
            v.push_back(candidate);
            m[candidate].push_back(v);

            for(int j = candidate + 1; j <= target; j++) {

                if(m.count(j - candidate)) {
                    vector<vector<int>> a = m[j - candidate];

                    for(int k = 0; k < a.size(); k++) {
                        vector<int> tem = a[k];
                        tem.push_back(candidate);
                        m[j].push_back(tem);
                    }
                }
            }
       }

       return m[target];
    }
};