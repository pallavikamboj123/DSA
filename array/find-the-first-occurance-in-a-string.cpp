class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> index;

        for(int i = 0; i < haystack.length(); i++) {
            if(haystack[i] == needle[0]) index.push_back(i);
        }


        for(int i = 0; i < index.size(); i++) {
            int a = index[i];
            int j = 0;
            while(a < haystack.length() && a < a + needle.length()) {
                if(needle[j] != haystack[a]) break;
                a++;
                j++;
            }

            if(j == needle.length()) return a - needle.length();
        }

        return -1;
    }
};