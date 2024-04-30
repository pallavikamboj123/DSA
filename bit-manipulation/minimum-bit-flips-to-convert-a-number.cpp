class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start^goal;

        int count = 0;
        while(x > 0) {
            int bit = x & 1;
            x = x >> 1;
            if(bit) count++;
        }

        return count;
    }
};