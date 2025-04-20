class Solution {
public:
    int maximumSwap(int num) {
      string numStr = to_string(num);
      int size = numStr.size();
      vector<pair<char, int>> cache(size);
      cache[size - 1] = make_pair(numStr[size - 1], size - 1);

      for (int i = size - 2; i >= 0; --i) {
        cache[i] = numStr[i] > cache[i + 1].first ? make_pair(numStr[i], i) : cache[i + 1];
      }

      for (int i = 0; i < size; ++i) {
        if (numStr[i] != cache[i].first) {
          swap(numStr[i], numStr[cache[i].second]);
          break;
        } 
      }

      return stoi(numStr);
    }
};