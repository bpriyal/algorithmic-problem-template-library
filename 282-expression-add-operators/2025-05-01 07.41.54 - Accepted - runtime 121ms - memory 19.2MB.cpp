class Solution {
    vector<string> result;
    int size;
    void recurse(const string& num, int target, int i, long prevOperand, long currOperand, long value, vector<string>& op) {
      if (i == size) {
        if (value == target && currOperand == 0) { // value equal and there is nothing to evaluate
          string r;
          for (int i = 1; i < op.size(); ++i) r += op[i];
          result.emplace_back(r);
        }
      } else {
        currOperand = currOperand * 10 + num[i] - '0';
        auto currOperandStr = to_string(currOperand);

        // No OP, to avoid leading zeros 1 + 05 OR 1 * 05
        if (currOperand > 0) recurse(num, target, i + 1, prevOperand, currOperand, value, op);

        // Addition
        op.emplace_back("+");
        op.emplace_back(currOperandStr);
        recurse(num, target, i + 1, currOperand, 0, value + currOperand, op);
        op.pop_back();
        op.pop_back();

        if (op.size() > 0) {
          // subtraction
          op.emplace_back("-");
          op.emplace_back(currOperandStr);
          recurse(num, target, i + 1, -currOperand, 0, value - currOperand, op);
          op.pop_back();
          op.pop_back();

          // MULT
          op.emplace_back("*");
          op.emplace_back(currOperandStr);
          recurse(num, target, i + 1, currOperand * prevOperand, 0, value - prevOperand + (currOperand * prevOperand), op);
          op.pop_back();
          op.pop_back();
        }
      }
    }
public:
    vector<string> addOperators(string num, int target) {
      size = num.size();
      vector<string> op;
      recurse(num, target, 0, 0, 0, 0, op);
      return result;
    }
};