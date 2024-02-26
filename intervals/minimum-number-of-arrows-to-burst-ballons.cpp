class Solution {
public:

    bool static sorted(const vector<int>&v1 , const vector<int>&v2)
    {
        return v1[0] < v2[0];
    }

    int findMinArrowShots(vector<vector<int>>& points) {

        sort(points.begin(),points.end(),sorted);

        int end = points[0][1];
        int count = 0;
        int min_end = end;

        for(int i = 1; i < points.size(); i++) {
            int start = points[i][0];

            if(start <= end && start <= min_end) {
                end = points[i][1];
                min_end = min(min_end, end);
            }
            else {
                count++;
                end = points[i][1];
                min_end = end;
            }
        }

        count++;

        return count;
    }
};