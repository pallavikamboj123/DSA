class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;

        for(int i = 0; i < nums.size(); i++) {
            m[i] = nums[i];
        }

        sort(nums.begin(), nums.end());

        int i = 0, j = nums.size() - 1;

        vector<int> ans;

        while(i < j) {
            if(nums[i] + nums[j] == target) {

                unordered_map<int, int>::iterator itr;

                for(itr = m.begin(); itr != m.end(); itr++) {
                    if(itr->second == nums[i] || itr->second == nums[j]) {
                        ans.push_back(itr->first);
                    }
                }

                return ans;
            }

            if(nums[i] + nums[j] > target) {
                j--;
            }
            else{
                i++;
            }
        }

        return ans;
    }
};
