class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int arr[n];

        for(int i = 0; i < n; i++) arr[i] = INT_MAX;

        arr[0] = 0;

        for(int i = 0; i < n; i ++) {
            int val = nums[i];
            for(int j = i + 1; j <= val + i; j++) {
                if(j >= n) break;
                arr[j] = min(arr[j], arr[i] + 1);
            }
        }

        return arr[n-1];
    }
};