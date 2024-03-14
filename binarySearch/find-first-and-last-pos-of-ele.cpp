class Solution {
public:
    vector<int> helper(vector<int>& nums, int l, int r, int t) {
        vector<int> ans;

        if(l > r) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }

        int mid = l + (r - l)/2;

        if(nums[mid] == t) {
            int finalStart = mid;
            int finalEnd = mid;
            vector<int> left = helper(nums, l, mid -1, t);
            vector<int> right = helper(nums, mid + 1, r, t);

            finalStart = left[0] == -1 ? mid : left[0];
            finalEnd = right[1] == -1 ? mid : right[1];

            ans.push_back(finalStart);
            ans.push_back(finalEnd);
            return ans;
        }
        else if(nums[mid] < t) {
            return helper(nums, mid + 1, r, t);
        }
        else {
            return helper(nums, l, mid - 1, t);
        }

        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return helper(nums, 0, nums.size() - 1, target);
    }
};