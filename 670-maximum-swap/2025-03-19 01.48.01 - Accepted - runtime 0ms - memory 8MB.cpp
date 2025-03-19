class Solution {
public:
    int maximumSwap(int num) {
      string numStr = to_string(num);
      int size = numStr.size();

      vector<int> maxNumIdx(size);
      maxNumIdx[size - 1] = size - 1;
      for (int i = size - 2; i >= 0; --i) {
        maxNumIdx[i] = (numStr[maxNumIdx[i + 1]] >= numStr[i]) ? maxNumIdx[i + 1] : i; 
      }

      for (int i = 0; i < size; ++i) {
        if (numStr[i] != numStr[maxNumIdx[i]]) {
          swap(numStr[i], numStr[maxNumIdx[i]]);
          break;
        }
      }

      return stoi(numStr);
    }
};