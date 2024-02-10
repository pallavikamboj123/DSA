class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string a = "";
        string space = " ";
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ' && a.length() > 0) {
                v.push_back(a);
                a = "";
            }
            else if(s[i] != ' '){
                a += s[i];
            }
            
        }

        if(a.length() > 0) v.push_back(a);
        string ans = "";
        for(int i = v.size() - 1; i >=0; i--) {
            
            ans += v[i] + (i > 0 ? " " : "");
        }

        return ans;
    }
};