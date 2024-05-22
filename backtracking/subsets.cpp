class Solution {
public:
    vector<vector<int>> ans;
    void subsets(vector<int>& nums, int index, vector<int> a) {
        if(index  >= nums.size()) {
            ans.push_back(a);
            return;
        }

        subsets(nums, index + 1, a);
        a.push_back(nums[index]);
        subsets(nums, index + 1, a);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> a;
        subsets(nums, 0, a);

        return ans;
    }
};


class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList();

        ans.add(new ArrayList<Integer>());

        for(Integer num: nums) {
            List<List<Integer>> newSubset = new ArrayList();

            for(List<Integer> curr : ans) {
                newSubset.add(
                    new ArrayList<Integer>(curr) {
                        {
                            add(num);
                        }
                    }
                );
            }

            for(List<Integer> curr : newSubset ) {
                ans.add(curr);
            }
        }

        return ans;
    }
}