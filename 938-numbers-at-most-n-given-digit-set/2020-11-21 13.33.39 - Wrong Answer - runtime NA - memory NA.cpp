class Solution {
    int result;
    void util(const vector<string>& digits, int n,long long int run) {
        if (run > n) {
            return;
        }
        if (run > 0 && run <= n) {
            ++result;
        }
        for(auto &s:digits) {
            util(digits,n,run*10+(s[0]-'0'));
        }
    }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        result = 0;
        string N = to_string(n);
        int sizeDigits = digits.size();
        int NSize = N.size();
        for(int i = 1;i <NSize;++i) {
            result += pow(sizeDigits,i);
        }
        
        for(int i = 0;i < NSize;++i) {
            bool flag = false;
            for(auto& d:digits) {
                if(d[0] < N[i]) {
                    result += pow(sizeDigits,NSize-i-1);
                } else if (d[0] == N[i]) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                return result;
            }
        }
        //util(digits,n,0);
        return result+1;
    }
};