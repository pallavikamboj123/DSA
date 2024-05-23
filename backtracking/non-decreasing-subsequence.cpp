class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, int index, vector<int>& a) {
        if(a.size() >= 2) {
            ans.push_back(a);
        }

        unordered_set<int> st;

        for(int i = index; i < nums.size(); i++) {
            if((a.empty() || nums[i] >= a.back()) && st.find(nums[i]) == st.end()) {
                a.push_back(nums[i]);

                backtrack(nums, i + 1, a);

                a.pop_back();

                st.insert(nums[i]);
            }
        }

    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> a;
        backtrack(nums, 0, a);
        return ans;
    }
};