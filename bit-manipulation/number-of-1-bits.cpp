class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        while(n > 0) {
            int bit = n & 1;

            count += bit ? 1 : 0;

            n >>= 1;
        }

        return count;
    }
};