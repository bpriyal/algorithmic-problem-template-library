class Solution {
public:
    double myPow(double x, int n) {
      if (x == 0) return 0;
      if (x == 1) return 1;
      if (n == 0) return 1;
      long nLong = n;

      if (nLong < 0) {
        x = 1 / x;
        nLong = -nLong;
      }

      double result = 1;

      while (nLong) {
        if (nLong % 2 == 1) {
          result *= x;
          --nLong;
        }
        x = x * x;
        nLong /= 2;
      }

      return result;
    }
};