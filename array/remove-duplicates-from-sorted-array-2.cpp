class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        int last = nums[0];

        int i = 0;
        int j = 0;
        while(j < nums.size()) {
            if(nums[j] != last) {
                count = 0;
                last = nums[j];
            }

            if(count < 2) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;

                count++;
                i++;
                j++;
            }
            else {
                j++;
            }
        }

        return i;
    }
};