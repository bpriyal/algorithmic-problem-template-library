class Solution {
public:
    bool isPalindrome(int x) {
      if (x < 0) return false;
      if (x == 0) return true;
      if (x / 10 == 0) return true;
      if (x % 10 == 0) return false;
      
      int revertedNumber = 0;
      while (x > revertedNumber) {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
      }

      return x == revertedNumber || x == revertedNumber / 10;
    }
};