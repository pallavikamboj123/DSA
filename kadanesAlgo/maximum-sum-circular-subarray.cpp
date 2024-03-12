class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int minSum = nums[0];
        int curr = nums[0];
        int total = nums[0];

        int maxSum = nums[0];
        int currMax = nums[0];

        for(int i = 1; i < n; i++) {
            currMax = max(nums[i], currMax + nums[i]);
            maxSum = max(maxSum, currMax);
        }

        for(int i = 1; i < n; i++) {

            curr = min(curr + nums[i], nums[i]);
            minSum = min(curr, minSum);
            total += nums[i];
        }

        if(total != minSum) {
            return max(total - minSum, maxSum);
        }
        else {
            return maxSum;
        }

    }
};