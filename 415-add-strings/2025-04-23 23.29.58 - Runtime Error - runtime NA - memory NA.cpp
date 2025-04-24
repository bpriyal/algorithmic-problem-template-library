class Solution {
public:
    string addStrings(string num1, string num2) {
      int size1 = num1.size();
      int size2 = num2.size();
      int i = size1 - 1, j = size2 - 1;
      int carry = 0;
      int result = 0;
      int factor = 1;

      while (i >= 0 && j >= 0) {
        int sum =  (num1[i] - '0') + (num2[j] - '0') + carry;
        result = (sum % 10) * factor + result;
        factor *= 10;
        carry = sum / 10;
        --i;
        --j;
      }

      while (i >= 0) {
        int sum =  (num1[i] - '0') + carry;
        result = (sum % 10) * factor + result;
        factor *= 10;
        carry = sum / 10;
        --i;
      }

      while (j >= 0) {
        int sum =  (num2[j] - '0') + carry;
        result = (sum % 10) * factor + result;
        factor *= 10;
        carry = sum / 10;
        --j;
      }

      if (carry) result = carry * factor + result;

      return to_string(result);
    }
};