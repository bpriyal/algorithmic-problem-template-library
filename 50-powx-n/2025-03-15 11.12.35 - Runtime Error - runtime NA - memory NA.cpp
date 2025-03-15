class Solution {
public:
    double myPow(double x, int n) {
      if (x == 0) return 0;
      if (n == 0) return 1;

      if (n < 0) {
        x = 1 / x;
        n = -n;
      }

      return x * myPow(x, n - 1);
    }
};