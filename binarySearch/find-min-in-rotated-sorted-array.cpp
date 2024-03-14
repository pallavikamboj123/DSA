class Solution {
public:
    int helper(vector<int>& nums, int left, int right) {
        if(left == right) return nums[left];

        int mid = left + (right - left)/2;

        if(mid - 1 >=0 && mid + 1 <= right && nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1]) {
            return nums[mid];
        }

        if(nums[mid] > nums[right]) {
            return helper(nums, mid + 1, right);
        }
        else return helper(nums, left, mid - 1);
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] < nums[n-1]) return nums[0];

        return helper(nums, 0, n-1);
    }
};