class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int p = pow(2, n);

        int sum = 0;
        for(int i = 0; i < p; i++) {
            int curr = 0;

            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) {
                    curr = curr ^ nums[j];
                }
            }

            sum += curr;
        }

        return sum;

    }
};