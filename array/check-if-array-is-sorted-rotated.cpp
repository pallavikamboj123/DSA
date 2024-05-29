class Solution {
public:
    int last;
    bool isSorted(vector<int>& nums, int i, int j) {
        if(j < i) return true;

        for(int k = i; k <= j; k++) {
            if(nums[k] < last) return false;
            last = nums[k];
        }

        return true;
    }
    bool check(vector<int>& nums) {
        int n = nums.size();
        int index = 0;

        for(int i = 1; i < n; i++) {
            if(nums[i] <= nums[index] && nums[i] != nums[i - 1]) index = i;
        }

        last = nums[index];

        bool left = isSorted(nums, index, n - 1);
        bool right = isSorted(nums, 0, index - 1);

        if(!left || !right) return false;

        return true;

    }
};



