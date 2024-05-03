class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        vector<bool> visited(bank.size(), false);
        queue<string> q;

        q.push(startGene);
        int level = 0;

        while(!q.empty()) {
            int size = q.size();
            level++;

            int k = 0;
            while(k < size) {
                string gene = q.front();
                q.pop();

                if(gene == endGene) return level - 1;

                for(int i = 0; i < bank.size(); i++) {
                    if(visited[i]) continue;
                    int noOfMutations = 0;
                    for(int j = 0; j < 8; j++) {
                        if(gene[j] != bank[i][j]) noOfMutations++;
                    }

                    if(noOfMutations == 1) {
                        q.push(bank[i]);
                        visited[i] = true;
                    }
                }

                k++;
            }
        }

        return -1;
    }
};