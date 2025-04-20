class Solution {
public:
    int maximumSwap(int num) {
      string numStr = to_string(num);
      int size = numStr.size();
      vector<int> cache(size);
      cache[size - 1] = size - 1;

      for (int i = size - 2; i >= 0; --i) {
        cache[i] = numStr[i] > numStr[cache[i + 1]] ? i : cache[i + 1];
      }

      for (int i = 0; i < size; ++i) {
        if (numStr[i] != numStr[cache[i]]) {
          swap(numStr[i], numStr[cache[i]]);
          break;
        } 
      }

      return stoi(numStr);
    }
};

// O(2n), O(n)