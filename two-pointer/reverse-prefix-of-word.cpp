class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = -1;
        int n = word.length();

        for(int i = 0; i < n; i++) {
            if(word[i] == ch) {
                index = i;
                break;
            }
        }

        if(index == -1) return word;

        int i = 0, j = index;
        while(i < j) {
            char temp = word[j];
            word[j] = word[i];
            word[i] = temp;
            i++;
            j--;
        }

        return word;
    }
};