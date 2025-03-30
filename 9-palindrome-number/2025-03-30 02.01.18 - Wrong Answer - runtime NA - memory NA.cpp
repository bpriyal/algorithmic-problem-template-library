class Solution {
public:
    bool isPalindrome(int x) {
      if (x < 0) return false;
      if (x == 0) return true;
      if (x / 10 == 0) return true;
      if (x % 11 == 0) return true;
      return false;
    }
};