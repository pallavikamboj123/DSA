class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        if( k == n) {
            return;
        }

        if(k > n) {
            k = k % n;
        }

        reverse(nums.begin(), nums.end());

        int i = 0;
        int j = k -1;

        while( i < j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j--;
            i++;
        }

        i = k;
        j = n - 1;

        while( i < j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j--;
            i++;
        }
        return;
    }
};