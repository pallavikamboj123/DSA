class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        unordered_map<int,int> mapp;
        int best = 0;
        for(int i = 0;i<arr.size();i++){
            mapp[arr[i]] = 1;
        }
        int maxval = 0;
        for(auto m:mapp){
            if(mapp.count(m.first - 1) == 0){
                int curr = m.first;
                int anscurr = 1;
                while(mapp.count(curr+1) > 0){
                    curr++;
                    anscurr++;
                }
                maxval = max(maxval, anscurr);
            }
        }
        return maxval;
    }
};