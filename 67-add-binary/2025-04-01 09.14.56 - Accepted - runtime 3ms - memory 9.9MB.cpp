class Solution {
public:
    string addBinary(string a, string b) {
      int sizea = a.size();
      int sizeb = b.size();
      int i = sizea - 1, j = sizeb - 1, carry = 0;
      string output;

      auto getSumCarry = [&carry](int num1, int num2) -> int {
        int sum = num1 + num2 + carry;
        switch (sum) {
          case 0: sum = 0; carry = 0; break;
          case 1: sum = 1; carry = 0; break;
          case 2: sum = 0; carry = 1; break;
          case 3: sum = 1; carry = 1; break;
        }
        return sum;
      };

      while (i >= 0 && j >= 0) {
        output += to_string(getSumCarry(a[i] - '0', b[j] - '0'));
        --i;
        --j;
      }

      while (i >= 0) {
        output += to_string(getSumCarry(a[i] - '0', 0));
        --i;
      }

      while (j >= 0) {
        output += to_string(getSumCarry(b[j] - '0', 0));
        --j;
      }

      if (carry) output += to_string(carry);

      reverse(output.begin(), output.end());

      return output;
    }
};