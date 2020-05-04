class Solution {
public:
    unsigned int findComplement(unsigned int num) {
        unsigned int nbits = floor(log2(num)) + 1;
        unsigned int allones = (1 << nbits) - 1;
        return allones^num;
    }
};