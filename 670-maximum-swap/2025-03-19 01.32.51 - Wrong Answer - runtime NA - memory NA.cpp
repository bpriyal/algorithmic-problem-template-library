class Solution {
public:
    int maximumSwap(int num) {
      string numStr = to_string(num);
      int size = numStr.size();

      vector<pair<int, int>> maxNumIdxPairs(size);
      maxNumIdxPairs[size - 1] = { numStr[size - 1] - '0', size - 1 };
      for (int i = size - 2; i >= 0; --i) {
        maxNumIdxPairs[i] = (maxNumIdxPairs[i + 1].first > numStr[i] - '0') ?
                            make_pair(maxNumIdxPairs[i + 1].first, maxNumIdxPairs[i + 1].second) : make_pair(numStr[i] - '0', i); 
      }

      for (const auto& [p1, p2] : maxNumIdxPairs) {
        cout << "max: " << p1 << ", idx: " << p2 << endl;
      }

      for (int i = 0; i < size; ++i) {
        if (numStr[i] - '0' != maxNumIdxPairs[i].first) {
          swap(numStr[i], numStr[maxNumIdxPairs[i].second]);
          break;
        }
      }

      return stoi(numStr);
    }
};