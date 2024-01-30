class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;

        sort(nums.begin(), nums.end());

        int count = 0;
        int start_index = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == val) {
                count++;

                if(start_index == -1) start_index = i;
             }
        }

        int j = nums.size() - 1;

        start_index = start_index == -1 ? j : start_index;

        while( start_index <= j) {
            int temp = nums[start_index];
            nums[start_index] = nums[j];
            nums[j] = temp;

            start_index++;
            j--;
        }

        return nums.size() - count;

    }
};