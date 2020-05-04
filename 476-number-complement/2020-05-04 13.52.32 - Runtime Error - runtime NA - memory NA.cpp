class Solution {
public:
    int findComplement(int num) {
        int nbits = floor(log2(num)) + 1;
        int allones = (1 << nbits) - 1;
        return allones^num;
    }
};