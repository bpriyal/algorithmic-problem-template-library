class Solution {
public:
    int maximumSwap(int num) {
      string numStr = to_string(num);
      int size = numStr.size();
      // vector<int> cache(size);
      // cache[size - 1] = size - 1;

      // for (int i = size - 2; i >= 0; --i) {
      //   cache[i] = numStr[i] > numStr[cache[i + 1]] ? i : cache[i + 1];
      // }

      // for (int i = 0; i < size; ++i) {
      //   if (numStr[i] != numStr[cache[i]]) {
      //     swap(numStr[i], numStr[cache[i]]);
      //     break;
      //   } 
      // }

      // return stoi(numStr);

      int swapIdx1 = -1;
      int swapIdx2 = -1;
      int maxIdx = size - 1;

      for (int i = size - 2; i >= 0; --i) {
        if (numStr[i] > numStr[maxIdx]) maxIdx = i;
        else if (numStr[i] != numStr[maxIdx]){
          swapIdx1 = i;
          swapIdx2 = maxIdx;
        }
      }

      if (swapIdx1 != -1 && swapIdx2 != -1) swap(numStr[swapIdx1], numStr[swapIdx2]);
      return stoi(numStr);
    }
};

// O(2n), O(n)