class Solution {
public:
    string addStrings(string num1, string num2) {
      int size1 = num1.size();
      int size2 = num2.size();

      int i = size1 - 1, j = size2 - 1, carry = 0;
      string result;
      while (i >= 0 || j >= 0 || carry != 0) {
        int sum = carry + (i >= 0 ? num1[i] - '0' : 0) + (j >= 0 ? num2[j] - '0' : 0);
        result += (sum % 10 + '0');
        carry = sum / 10;
        --i;
        --j;
      }
      reverse(result.begin(), result.end());
      return result;
    }
};