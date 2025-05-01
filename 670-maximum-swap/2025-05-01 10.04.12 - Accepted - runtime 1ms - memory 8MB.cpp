class Solution {
public:
    int maximumSwap(int num) {
      string numStr = to_string(num);
      vector<int> rightMostIndex(10, -1);
      for (int i = 0; i < numStr.size(); ++i) rightMostIndex[numStr[i] - '0'] = i;

      for (int i = 0; i < numStr.size(); ++i) {
        for (int j = 9; j >= 0; --j) {
          if ((numStr[i] - '0') < j && rightMostIndex[j] > i) {
            swap(numStr[i], numStr[rightMostIndex[j]]);
            return stoi(numStr);
          }
        }
      }

      return num;
    }
};

// O(2n), O(n)