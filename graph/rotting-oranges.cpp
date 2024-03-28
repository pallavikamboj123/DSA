class Solution {
public:
    int X[4] = {0,-1,0,1};
    int Y[4] = {-1,0,1,0};

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        if(n == 0){
            return 0;
        }
        int m = grid[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }

        int count = 0;

        while(!q.empty()){
            int k = q.size();
             bool check = true;
            while(k--)
            {pair<int,int> curr = q.front();
            q.pop();

            for(int i = 0;i<4;i++){
                int new_x = curr.first + X[i];
                int new_y = curr.second + Y[i];
                if(new_x <0 || new_x >= n || new_y < 0 || new_y >= m ){
                    continue;
                }
                if(grid[new_x][new_y] == 1){
                    check = false;
                    grid[new_x][new_y] = 2;
                    q.push({new_x,new_y});
                }
            }}
            if(!check){
                count++;
            }
        }

        bool check = true;
        for(int i =0 ;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    check = false;
                    break;
                }
            }
        }
        if(check){
            return count;
        }
        else{
            return -1;
        }
    }
};