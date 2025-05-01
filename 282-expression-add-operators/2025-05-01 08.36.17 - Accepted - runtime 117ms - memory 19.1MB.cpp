class Solution {
    vector<string> result;
    int size;
    void recurse(const string& num, int target, int i, long prevOperand, long currOperand, long value, vector<string>& runStr) {
      if (i == size) {
        if (value == target && currOperand == 0) {
          string temp;
          for (int i = 1; i < runStr.size(); ++i) temp += runStr[i];
          result.emplace_back(temp);
        }
      } else {
        currOperand = currOperand * 10 + (num[i] - '0');
        auto currOperandStr = to_string(currOperand);

        if (currOperand > 0) recurse(num, target, i + 1, prevOperand, currOperand, value, runStr);

        // ADD
        runStr.emplace_back("+");
        runStr.emplace_back(currOperandStr);
        recurse(num, target, i + 1, currOperand, 0, value + currOperand, runStr);
        runStr.pop_back();
        runStr.pop_back();

        if (runStr.size() > 0) {
          // SUB
          runStr.emplace_back("-");
          runStr.emplace_back(currOperandStr);
          recurse(num, target, i + 1, -currOperand, 0, value - currOperand, runStr);
          runStr.pop_back();
          runStr.pop_back();

          // MULT
          runStr.emplace_back("*");
          runStr.emplace_back(currOperandStr);
          recurse(num, target, i + 1, prevOperand * currOperand, 0, value - prevOperand + (prevOperand * currOperand), runStr);
          runStr.pop_back();
          runStr.pop_back();
        }
      }
    }
public:
    vector<string> addOperators(string num, int target) {
      size = num.size();
      vector<string> runStr;
      recurse(num, target, 0, 0, 0, 0, runStr);
      return result;
    }
};