class Solution {
public:
    bool isStrobogrammatic(string num) {
      int size = num.size();
      if (size == 1) {
        return num == "0" || num == "1" || num == "8";
      }
      int i = 0, j = size - 1;
      while (i <= j) {
        if (num[i] == '8' && num[j] == '8' || num[i] == '0' && num[j] == '0' ||
            num[i] == '1' && num[j] == '1' || num[i] == '6' && num[j] == '9' ||
            num[i] == '9' && num[j] == '6') {
          ++i;
          --j;
        } else return false;
      }
      return true;
    }
};