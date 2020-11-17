class Solution {
public:
    int mirrorReflection(int p, int q) {
        int m = 1, n = 1; /* m is room ext, n is reflections */
        while (m*p != n*q) {
            ++n;
            m = n*q/p;
        }
        if (m%2 != 0 && n%2 == 0) {
            return 2;
        }
        if (m%2 == 0 && n%2 != 0) {
            return 0;
        }
        if (m%2 != 0 && n%2 != 0) {
            return 1;
        }
        return -1;
    }
};