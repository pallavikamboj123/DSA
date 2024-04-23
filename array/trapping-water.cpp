class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left[n];
        int right[n];


        int l_max = INT_MIN, r_max = INT_MIN;
        for(int i = 0; i < n; i++) {
            if(l_max > height[i]) {
                left[i] = l_max;
            }

            else {
                left[i] = height[i];
                l_max = height[i];
            }
        }

        for(int i = n-1; i >= 0; i--) {
            if(r_max > height[i]) {
                right[i] = r_max;
            }

            else {
                right[i] = height[i];
                r_max = height[i];
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += min(left[i], right[i]) - height[i];
        }

        return ans;
    }
};


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int left_index = 0;
        int right_index = n - 1;

        int m = INT_MIN;
        int ans = 0;


        while(left_index <= right_index) {
            int curr_min = min(height[left_index], height[right_index]);

            m = max(m, curr_min);

            if(height[left_index] < height[right_index]) {
                ans += m - height[left_index];
                left_index++;
            }
            else {
                ans += m - height[right_index];
                right_index--;
            }
        }

        return ans;
    }
};