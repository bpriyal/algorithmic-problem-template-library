class Solution {
public:
    int maximumSwap(int num) {
      string numStr = to_string(num);
      int size = numStr.size();
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