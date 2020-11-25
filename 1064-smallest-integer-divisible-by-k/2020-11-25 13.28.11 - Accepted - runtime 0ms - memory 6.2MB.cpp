class Solution {
public:
    int smallestRepunitDivByK(int K) {
        int num = 0;
        for(int i = 1;i <= K;++i) {
            num = (num*10)%K+1;
            if (num%K == 0) {
                return i;
            }
        }
        return -1;
    }
};