class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;

        for(int i = 0; i < wordList.size(); i++) {
            words.insert(wordList[i]);
        }

        queue<string> q;
        q.push(beginWord);
        words.erase(beginWord);
        int level = 0;

        while(!q.empty()) {
            int size = q.size();
            level++;
            for(int i = 0; i < size; i++) {
                string front = q.front();
                q.pop();

                if(front == endWord) return level;

                for(int j = 0; j < front.length(); j++) {
                    char c = front[j];
                    for(int k = 0; k < 26; k++) {
                        front[j] = 'a' + k;

                        if(words.find(front) != words.end()) {
                            q.push(front);
                            words.erase(front);
                        }
                    }
                    front[j] = c;
                }
            }
        }

        return 0;
    }
};