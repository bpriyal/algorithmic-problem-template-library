class Solution {
public:
    double myPow(double x, int n) {
      if (x == 0) return 0;
      if (n == 0) return 1;

      if (n < 0) {
        x = 1 / x;
        n = -n;
      }

      double result = 1;
      while (n) {
        if (n % 2) {
          result *= x;
          --n;
        }
        x = x * x;
        n = n / 2;
      }
      return result;

      // // Binary exponentiation = O(logn)
      // if (n % 2) return x * myPow(x * x, (n - 1) / 2);
      // else return myPow(x * x, n / 2);
    }
};