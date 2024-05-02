#using sorting
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int i = 0, j = nums.size() - 1;

        while(i < j) {
            if(nums[i] + nums[j] == 0) return nums[j];

            if(nums[i] +nums[j] > 0) j--;
            else i++;
        }

        return -1;
    }
};

#using set

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = -1;
        for (int num : nums) {
            if (num > 0 && s.count(-num)) {
                ans = max(ans, num);
            }
        }
        return ans;
    }
};