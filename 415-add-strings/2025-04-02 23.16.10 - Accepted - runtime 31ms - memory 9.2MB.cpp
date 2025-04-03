class Solution {
public:
    string addStrings(string num1, string num2) {
      int size1 = num1.size();
      int size2 = num2.size();
      string result;

      int i = size1 - 1, j = size2 - 1, carry = 0;
      while (i >= 0 && j >= 0) {
        int sum = (num1[i] - '0') + (num2[j] - '0') + carry;
        if (sum > 9) {
          carry = sum / 10;
          sum %= 10;
        } else carry = 0;
        cout << sum << endl;
        result += '0' + sum;
        --i;
        --j;
      }

      while (i >= 0) {
        int sum = (num1[i] - '0') + carry;
        if (sum > 9) {
          carry = sum / 10;
          sum %= 10;
        } else carry = 0;
        result += '0' + sum;
        --i;
      }

      while (j >= 0) {
        int sum = (num2[j] - '0') + carry;
        if (sum > 9) {
          carry = sum / 10;
          sum %= 10;
        } else carry = 0;
        result += '0' + sum;
        --j;
      }

      if (carry) result += '0' + carry;

      
      reverse(result.begin(), result.end());
      return result;
    }
};