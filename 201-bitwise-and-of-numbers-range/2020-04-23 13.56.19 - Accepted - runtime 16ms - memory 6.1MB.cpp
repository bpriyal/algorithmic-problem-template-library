class Solution {
public:
    int msb(unsigned long int n) {
        int bit = 0;
        while (n) {
            ++bit;
            n = n >> 1;
        }
        return bit-1;
    }
    unsigned long int rangeBitwiseAnd(unsigned long int m,unsigned long int n) {
        unsigned long int result = 0;
        while (m && n) {
            int m_msb = msb(m);
            int n_msb = msb(n);
            if (m_msb != n_msb) {
                break;
            }
            int temp = 1 << m_msb;
            result = result + temp;
            m = m - temp;
            n = n - temp;
        }
        return result;
    }
};