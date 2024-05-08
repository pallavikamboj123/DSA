class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int i = 0, j = 0;
        while(i < n && j < n) {
            while(i < n && nums[i] != 0) {
                i++;
            }

            j = i + 1;
            while(j < n && nums[j] == 0) j++;

            if(i >= n || j >= n) return;

            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j++;
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int i = 0, j = 0;
        while(i < n && j < n) {
            while(i < n && nums[i] != 0) {
                i++;
            }

            j = i + 1;
            while(j < n && nums[j] == 0) j++;

            if(i >= n || j >= n) return;

            nums[i] = nums[j];
            nums[j] = 0;
            i++;
            j++;
        }
    }
};