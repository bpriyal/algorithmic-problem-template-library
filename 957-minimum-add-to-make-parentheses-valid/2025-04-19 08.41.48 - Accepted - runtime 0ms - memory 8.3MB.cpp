class Solution {
public:
    int minAddToMakeValid(string s) {
      int size = s.size();
      if (size == 0) return 0;
      int count = 0;
      int balance = 0;

      for (int i = 0; i < size; ++i) {
        if (s[i] == '(') ++balance;
        else {
          if (balance > 0) --balance;
          else ++count;
        }
      }

      return count + balance;
    }
};