class Solution {
public:
    int func(vector<int>& nums, int target, int start, int end) {
        if(start < 0 || end < 0) return 0;
        if(start >= nums.size() || end >=nums.size()) return nums.size();

        int mid = start + floor((end - start + 1)/2);

        if(nums[mid] == target) return mid;

        if(mid -1 >= 0 && nums[mid] > target && nums[mid-1] < target)  return mid;

        if(mid + 1 < nums.size() && nums[mid] < target && nums[mid + 1] > target) return mid +1;

        if(nums[mid] > target) return func(nums, target, start, mid -1);
        return func(nums, target, mid +1, end);
    }
    int searchInsert(vector<int>& nums, int target) {
        return func(nums, target, 0, nums.size() - 1);
    }
};