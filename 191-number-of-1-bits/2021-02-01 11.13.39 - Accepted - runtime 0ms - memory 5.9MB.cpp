class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while (n != 0) {
            result = n%2 == 0? result:result+1;
            n /= 2;
        }
        return result;
    }
};