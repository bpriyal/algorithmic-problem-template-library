class Solution {
public:
    double myPow(double x, int n) {
      if (x == 0) return 0;
      if (n == 0 || x == 1) return 1;
      long nLong = n;

      if (n < 0) {
        x = 1 / x;
        nLong = -nLong;
      }

      double result = 1;
      while (nLong) {
        if (nLong % 2) {
          result *= x;
          --nLong;
        }
        x = x * x;
        nLong = nLong / 2;
      }
      return result;

      // // Binary exponentiation = O(logn)
      // if (n % 2) return x * myPow(x * x, (n - 1) / 2);
      // else return myPow(x * x, n / 2);
    }
};