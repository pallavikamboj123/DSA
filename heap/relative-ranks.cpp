#using heap takes O(nlogn) time
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;

        for(int i = 0; i < score.size(); i++) {
            pq.push({score[i], i});
        }

        vector<string> ans(score.size(), "");
        int count = 0;
        while(!pq.empty()) {
            int index = pq.top().second;
            pq.pop();
            count++;
            switch(count) {
                case 1:
                    ans[index] = "Gold Medal";
                    break;
                case 2:
                    ans[index] = "Silver Medal";
                    break;
                case 3:
                    ans[index] = "Bronze Medal";
                    break;
                default:
                    ans[index] = to_string(count);
                    break;
            }
        }

        return ans;
    }
};

#array as map - O(n) time
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int maxEle = -1;
        int n = score.size();

        for(int i = 0; i < n; i++) {
            maxEle = max(maxEle, score[i]);
        }

        vector<int> index(maxEle + 1, -1);

        for(int i = 0; i < n; i++) {
            index[score[i]] = i;
        }

        int count = 0;
        vector<string> ans(n);
        for(int i = index.size() - 1; i >= 0; i--) {
            if(index[i] == -1) continue;

            count++;

            switch(count) {
                case 1:
                    ans[index[i]] = "Gold Medal";
                    break;
                case 2:
                    ans[index[i]] = "Silver Medal";
                    break;
                case 3:
                    ans[index[i]] = "Bronze Medal";
                    break;
                default:
                    ans[index[i]] = to_string(count);
                    break;
            }

        }

        return ans;
    }
};

#refactor code
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int maxEle = -1;
        int n = score.size();

        for(int i = 0; i < n; i++) {
            maxEle = max(maxEle, score[i]);
        }

        vector<int> index(maxEle + 1, -1);

        for(int i = 0; i < n; i++) {
            index[score[i]] = i;
        }

        int count = 0;
        vector<string> ans(n);
        vector<string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        for(int i = index.size() - 1; i >= 0; i--) {
            if(index[i] == -1) continue;

            count++;

            if(count <= 3) {
                ans[index[i]] = medals[count - 1];
            }
            else ans[index[i]] = to_string(count);
        }

        return ans;
    }
};