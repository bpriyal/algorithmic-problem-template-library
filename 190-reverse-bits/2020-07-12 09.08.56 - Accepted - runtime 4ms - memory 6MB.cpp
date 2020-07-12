class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int size = sizeof(n)*8;
        uint32_t reverse = 0;
        for (int i =0;i<size;++i) {
            if(n & (1<<i)) {
                reverse |= (1<<(size-1-i));
            }
        }
        return reverse;
    }
};