class Solution {
public:
    int n;
    int ans = 0;
    void backtrack(vector<int>& nums, int index, int k, vector<int>& curr) {
        if(curr.size() >= 1) {
            ans++;
        }

        for(int i = index; i < n; i++) {
            bool check = false;
            for(int j = 0; j < curr.size(); j++) {
                if(abs(curr[j] - nums[i]) == k) {
                    check = true;
                    break;
                }
            }

            if(!check) {
                curr.push_back(nums[i]);

                backtrack(nums, i + 1, k, curr);

                curr.pop_back();
            }
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        n = nums.size();
        vector<int> curr;

        backtrack(nums, 0, k, curr);

        return ans;
    }
};