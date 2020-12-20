class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long int n = 0;
        int i = 0;
        while (n < K) {
            n = isdigit(S[i]) ? n * (S[i]-'0') : n+1;
            ++i;
        }
        while (i > 0) {
            
            --i;
            if (isdigit(S[i])) {
                n = n / (S[i]-'0');
                K = K % n;
            } else {
                if (K % n == 0) {
                    string result(1,S[i]);
                    return result;
                }
                --n;
            }
        }
        return "";
    }
};