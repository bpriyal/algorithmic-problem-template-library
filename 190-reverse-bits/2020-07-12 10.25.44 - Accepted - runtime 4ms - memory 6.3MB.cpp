class Solution {
    unordered_map<uint32_t,uint32_t> cache;
    uint32_t reverseByte(uint32_t byte) {
        if (cache.find(byte) != cache.end()) {
            return cache[byte];
        }
        uint32_t value = (byte * 0x0202020202 & 0x010884422010) % 1023;
        cache.emplace(byte,value);
        return value;
    }
public:
    uint32_t reverseBits1(uint32_t n) {
        int power = 24;
        int reverse = 0;
        while(n) {
            reverse |= reverseByte(n & 0xff) << power;
            n = n >> 8;
            power -= 8;
        }
        return reverse;
    }
    uint32_t reverseBits(uint32_t n) {
        n = (n >>16) | (n << 16);
        n = ((n&0xff00ff00) >> 8) | ((n&0x00ff00ff) << 8);
        n = ((n&0xf0f0f0f0) >> 4) | ((n&0x0f0f0f0f) << 4);
        n = ((n&0xcccccccc) >> 2) | ((n&0x33333333) << 2);
        n = ((n&0xaaaaaaaa) >> 1) | ((n&0x55555555) << 1);
        return n;
    }
};