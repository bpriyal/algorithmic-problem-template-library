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
    uint32_t reverseBits(uint32_t n) {
        int power = 24;
        int reverse = 0;
        while(n) {
            reverse |= reverseByte(n & 0xff) << power;
            n = n >> 8;
            power -= 8;
        }
        return reverse;
    }
};