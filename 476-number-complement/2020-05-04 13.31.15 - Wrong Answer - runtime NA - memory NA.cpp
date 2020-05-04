class Solution {
public:
    void binary_rep(unsigned int num,vector<char> &binarynum) {
        while (num != 0) {
            if (num%2 == 0) {
                binarynum.push_back('0');
            } else {
                binarynum.push_back('1');
            }
            num = num/2;
        }
        binarynum.push_back('0');
    }
    
    unsigned int findComplement(unsigned int num) {
        vector<char> binarynum;
        binary_rep(num,binarynum);
        unsigned int mult = 1;
        unsigned int result;
        for (unsigned int i=0;i<binarynum.size();++i) {
            cout<<binarynum[i]<<endl;
            if (binarynum[i] == '0') {
                result += mult;
            }
            mult *= 2;
        }
        return result;
    }
};