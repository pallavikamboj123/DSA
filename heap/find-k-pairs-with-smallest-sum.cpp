class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            return a.first + a.second < b.first + b.second;
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> heap;

        int count = 0;

        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {

                if(count < k) {
                    heap.push(pair(nums1[i], nums2[j]));
                    count++;
                    continue;
                }

                pair<int, int> top = heap.top();
                if(count == k  && nums1[i] + nums2[j] < top.first + top.second) {
                    heap.pop();
                    heap.push(pair(nums1[i], nums2[j]));
                }
                else break;
            }
        }

        int i = 0;
        vector<vector<int>> ans;

        cout<<heap.size()<<endl;
        while(i < k) {
            vector<int> v;
            pair<int, int> top = heap.top();

            v.push_back(top.first);
            v.push_back(top.second);
            heap.pop();
            ans.push_back(v);
            i++;
        }

        return ans;
    }
};