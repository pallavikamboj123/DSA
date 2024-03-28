
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;

        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(v.size() == 0 || v[v.size() - 1] < nums[i]) {
                v.push_back(nums[i]);
            }
            else {
                auto index = lower_bound(v.begin(), v.end(), nums[i]);
                *index = nums[i];
            }
        }

        return v.size();
    }
};