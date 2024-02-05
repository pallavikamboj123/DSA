class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size() == 0){
            vector<int> v;
            return v;
        }
        int n = nums.size();
        vector<int> output(n,0);
        output[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--){
            output[i] = nums[i] * output[i+1];
        }
        int r = 1;
        for(int i = 0;i<n;i++){
            output[i] = r;
            if(i+1<n){
                output[i] *= output[i+1];
            }
             r = r*nums[i];
        }
        return output;
    }
};