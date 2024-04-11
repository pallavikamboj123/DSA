class Solution {
public:
    string removeDigit(string number, char digit) {
        int i = 0;

        while(i < number.length()) {
            if(i+1 < number.length() && number[i] == digit && number[i] < number[i+1]) {
                return number.substr(0, i) + number.substr(i+1);
            }
            i++;
        }

        int index;
        for(int j = number.length() - 1; j >= 0; j--) {
            if(number[j] == digit) {
                index = j;
                break;
            }
        }

        return number.substr(0, index) + number.substr(index+1);
    }
};