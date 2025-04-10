class Solution {
public:
    double myPow(double x, int n) {
      if (x <= 1) return x;
      if (n == 1) return x;
      if (n == 0) return 1;

      if (n < 0) {
        x = 1 / x;
        n = -n;
      }

      double result = 1;
      while (n) {
        if (n % 2 == 1) { // n is odd
          result *= x;
          --n;
        }
        x = x * x;
        n = n / 2;
      }

      return result;
    }
};