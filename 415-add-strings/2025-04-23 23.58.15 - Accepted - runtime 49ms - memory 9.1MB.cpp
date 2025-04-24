class Solution {
public:
    string addStrings(string num1, string num2) {
      int size1 = num1.size();
      int size2 = num2.size();
      int i = size1 - 1, j = size2 - 1;
      int carry = 0;
      string result;

      while (i >= 0 || j >= 0) {
        int sum = carry + (i >= 0 ? (num1[i--] - '0') : 0) + (j >= 0 ? (num2[j--] - '0') : 0);
        cout << sum % 10 << endl;
        result.push_back('0' + sum % 10);
        carry = sum / 10;
      }

      if (carry) result.push_back('0' + carry);
      reverse(result.begin(), result.end());
      return result;
    }
};