class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";

        if(numRows == 1) return s;

        int n = (numRows) + (numRows-2);


        for(int i = 0; i < numRows; i++) {
            for(int j = i; j < s.length(); ) {
                ans += s[j];
                int a = j + n - i*2;
                if(i != 0 && i != numRows - 1 && a < s.length() ) ans += s[j + n - i*2];

                j = j + n;
            }
        }

        return ans;
    }
};