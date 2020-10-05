class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0) {
            return 1;
        }
        
        vector<int> binary;
        
        while(N != 0) {
            binary.push_back(N%2);
            N /= 2;
        }
        
        int mult = 1;
        int result = 0;
        
        for(int i = 0;i < binary.size();++i) {
            result += binary[i] ? 0:mult;
            mult *= 2;
        }
        return result;
    }
};