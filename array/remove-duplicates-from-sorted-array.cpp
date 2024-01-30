class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;

        for(int i = 0; i < nums.size(); i++) s.insert(nums[i]);

        set<int>::iterator it;

        int i = 0;
        for(it = s.begin(); it != s.end(); it++) {
            nums[i] = *it;
            i++;
        }


        return s.size();
    }
};