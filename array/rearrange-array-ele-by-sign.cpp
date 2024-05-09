#brute force
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;

        for(auto num: nums) {
            if(num >= 0) pos.push_back(num);
            else neg.push_back(num);
        }

        int j = 0;
        for(int i = 0; i < pos.size(); i++) {
            nums[j++] = pos[i];
            nums[j++] = neg[i];
        }

        return nums;
    }
};