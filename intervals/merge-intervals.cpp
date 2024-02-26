class Solution {
public:
    bool compare(vector<int> a,vector<int> b){
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return intervals;

        sort(intervals.begin(),intervals.end(),[this](vector<int> a,vector<int> b){
            return compare(a,b);
        });

        vector<vector<int>> ans;

        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            vector<int> curr = intervals[i];

            if(curr[0] <= end) {
                end = max(curr[1], end);
                start = min(start, curr[0]);
            }
            else {
                vector<int> a;
                a.push_back(start);
                a.push_back(end);
                start = curr[0];
                end = curr[1];

                ans.push_back(a);
            }
        }

        vector<int> a;
        a.push_back(start);
        a.push_back(end);

        ans.push_back(a);

        return ans;

    }
};