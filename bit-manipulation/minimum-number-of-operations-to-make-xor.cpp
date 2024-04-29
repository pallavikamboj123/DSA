#https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/description/?envType=daily-question&envId=2024-04-29
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x = nums[0];
        int n = nums.size();

        for(int i = 1; i < n; i++) {
            x = x ^ nums[i];
        }

        int ans = 0;

        while(x > 0 || k > 0) {
            int bit = x & 1;
            int bit2 = k & 1;

            x = x >> 1;
            k = k >> 1;

            if(bit != bit2) {
                ans++;
            }
        }

        return ans;
    }
};