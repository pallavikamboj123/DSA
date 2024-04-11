class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;

        int i = 0, n = num.length();

        while(i < n ) {
            if(s.empty()) {
                s.push(num[i]);
                i++;
                continue;
            }

            while(k > 0 && !s.empty() && s.top() > num[i]) {
                s.pop();
                k--;
            }

            s.push(num[i]);
            i++;
        }

        while(k != 0) {
            s.pop();
            k--;
        }

        string ans = "";
        while(!s.empty()) {
            ans += s.top();
            s.pop();
        }

        int j;
        for(j = ans.length() - 1; j >= 0; j--) {
            if(ans[j] != '0') break;
        }

        string a = ans.substr(0, j+1);

        reverse(a.begin(), a.end());
        return a.length() == 0 ? "0" : a;
    }
};