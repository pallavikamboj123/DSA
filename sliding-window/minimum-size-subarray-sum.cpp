class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int sum = nums[0];
        int ans = INT_MAX;
        int n = nums.size();

        while(i < n && j < n) {
            if( sum >= target) {
                ans = min(ans, j - i +1);
            }

            if( sum > target ) {
                sum = sum - nums[i];
                i++;
            }
            else {
                int a =  j + 1 < n ? nums[j+1] : 0;
                sum = sum + a;
                j++;
            }
        }

        while( i < n) {
            if(sum >= target){
                ans = min( ans, j - i);
            }

            sum = sum - nums[i];
            i++;
        }

        return ans == INT_MAX ? 0 : ans;
    }
};