class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
      vector<vector<int>> res;

      sort(num.begin(), num.end());

      for(int i=0;i<num.size();i++){
          int target = -num[i];
          int back = num.size()-1;
          int front = i+1;
          while(front<back){
              int sum = num[front] + num[back];
              if(sum < target){
                  front++;
              }
              else if(sum>target)
                  back--;
              else{
                  vector<int> triplet(3,0);
                  triplet[0] = num[i];
                  triplet[1] = num[front];
                  triplet[2] = num[ back];
                  res.push_back(triplet);
                  while(front < back && num[front] == triplet[1]) front++;
                  while(front < back && num[back] == triplet[2]) back--;
              }
          }
            while(i+1 < num.size() && num[i+1] == num[i]){
                i++;
            }
      }
       return res;
    }

};