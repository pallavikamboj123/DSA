class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sum = 0;
        int ans = 0;
        for(auto num : nums) {
            if(num == 0) {
                ans = max(ans, sum);
                sum = 0;
            }
            else {
                sum++;
            }
        }

        return max(ans, sum);
    }
};