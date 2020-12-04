class Solution {
public:
    int kthFactor(int n, int k) {
        int size = 0;
        for(int i = 1;i <= n;++i) {
            if (n%i == 0) {
                ++size;
                if (size == k) {
                    return i;
                }
            }
        }
        return -1;
    }
};