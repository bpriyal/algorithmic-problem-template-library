class Solution {
public:
    double myPow(double x, int n) {
      if (x == 0 || x == 1) return x;
      if (n == 0) return 1;
      long nLong = n;

      if (n < 0) {
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
        nLong = nLong / 2;
      }

      return result;
    }
};