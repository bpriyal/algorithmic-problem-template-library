class Solution {
public:
    int maxScore(string s) {
        int size = s.size();
        int zeros[size],ones[size];
        zeros[0] = 0;
        ones[size-1] = 0;
        if (s[0] == '0') zeros[0] =1;
        if (s[size-1] == '1') ones[size-1] =1;
        for (int i=1;i<size;++i) {
            if(s[i] == '0') {
                zeros[i] = zeros[i-1] +1;
            } else {
                zeros[i] =zeros[i-1];
            }
        }
        for(int i=size-2;i>=0;--i) {
            if (s[i] == '1') {
                ones[i] = ones[i+1] +1;
            } else {
                ones[i] = ones[i+1];
            }
        }
        int max = INT_MIN;
        for (int i=0;i<size-1;++i) {
            if (zeros[i]+ones[i+1] > max) {
                max =  zeros[i] + ones [i+1];
            }
        }
        return max;
    }
};