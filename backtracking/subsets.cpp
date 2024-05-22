class Solution {
public:
    vector<vector<int>> ans;
    void subsets(vector<int>& nums, int index, vector<int> a) {
        if(index  >= nums.size()) {
            ans.push_back(a);
            return;
        }

        subsets(nums, index + 1, a);
        a.push_back(nums[index]);
        subsets(nums, index + 1, a);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> a;
        subsets(nums, 0, a);

        return ans;
    }
};