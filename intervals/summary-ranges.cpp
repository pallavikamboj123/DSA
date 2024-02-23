class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;

        if(nums.size() == 0) return ans;

        long i = 0, j = 0;

        while(j < nums.size()) {
            if((long)nums[i] == (long)nums[j] || (long)nums[j] - (long)nums[j-1] == 1) {
                j++;
            }
            else {
                string a = "";
                a += to_string(nums[i]);
                a += "->";
                a += to_string(nums[j - 1]);

                if(i == j - 1) ans.push_back(to_string(nums[i]));
                else ans.push_back(a);

                i = j;
            }
        }

        string a = "";
        a += to_string(nums[i]);
        a += "->";
        a += to_string(nums[j-1]);

        if(i == j - 1) ans.push_back(to_string(nums[i]));
        else ans.push_back(a);

        return ans;
    }
};