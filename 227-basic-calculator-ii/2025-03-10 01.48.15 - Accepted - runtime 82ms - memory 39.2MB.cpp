class Solution {
    int extractNum(const string& s, int& startIdx, int size) {
      int num = 0;
      while (startIdx < size) {
        auto c = s[startIdx];
        if (c == ' ') {
          ++startIdx;
          continue;
        }
        if (!isdigit(c)) break;
        num = num * 10 + (c - '0');
        ++startIdx;
      }
      return num;
    }
public:
    int calculate(string s) {
      int size = s.size();
      std::deque<string> queue;

      int i = 0;
      while (i < size) {
        auto c = s[i];
        if (c == ' ') ++i;
        else if (c == '+' || c == '-') {
          queue.emplace_back(string(1, c));
          ++i;
        } else if (c == '*' || c == '/') {
          auto op1 = stoi(queue.back()); queue.pop_back();
          auto op2 = extractNum(s, ++i, size);
          queue.emplace_back(to_string(c == '*'? op1 * op2 : op1 / op2));
        } else if (isdigit(c)) {
          auto num = extractNum(s, i, size);
          queue.emplace_back(to_string(num));
        }
      }

      while (!queue.empty()) {
        if (queue.size() == 1) return stoi(queue.back());
        auto op1 = stoi(queue.front()); queue.pop_front();
        auto op = queue.front(); queue.pop_front();
        auto op2 = stoi(queue.front()); queue.pop_front();
        queue.emplace_front(to_string(op == "+"? op1 + op2 : op1 - op2));
      }
      return -1;
    }
};