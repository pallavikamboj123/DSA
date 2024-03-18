class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;

        int count = 31;
        while(n > 0) {
            int bit = n & 1;
            n >>= 1;

            ans += bit * static_cast<uint32_t>(pow(2, count));
            count--;
        }
        return ans;
    }
};