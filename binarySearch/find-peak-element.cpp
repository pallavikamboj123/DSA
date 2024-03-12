class Solution {
public:
    int helper(vector<int>& nums, int left, int right) {
        if(left > right) return right;

        int mid = left + (right - left)/2;

        if(mid - 1 >= 0 && mid + 1 < nums.size() && nums[mid] > nums[mid - 1] && nums[mid] > nums[mid+1])
            return mid;

        int ans;

        if(mid - 1 >= 0 && nums[mid] < nums[mid - 1]) {
            ans = helper(nums, left, mid -1);
        }
        else {
            ans = helper(nums, mid + 1, right);
        }

        return ans;
    }
    int findPeakElement(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};