class Solution {
public:
    string makeGood(string s) {
        stack<char> st;

        for(int i = 0; i < s.length(); i++) {
            if(st.empty()) {
                st.push(s[i]);
                continue;
            }
            int a = s[i];
            int b = st.top();

            if(abs(a-b) == 32) {
                st.pop();
            }
            else st.push(s[i]);
        }

        string ans = "";

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};