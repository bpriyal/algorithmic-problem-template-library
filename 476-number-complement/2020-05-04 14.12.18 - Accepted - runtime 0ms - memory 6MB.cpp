class Solution {
public:
    int findComplement(int num) {
        int nbits = log2(num) + 1;
        cout<<nbits<<endl;
        int allones = static_cast<unsigned>(1 << nbits) - 1;
        return allones^num;
    }
};